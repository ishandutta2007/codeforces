#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<set>
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){	if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)) {x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
inline void print(int x){
	if(x<0) x=-x,putchar('-');
	if(x>=10) print(x/10);
	putchar(x%10+48);
}
int n;
int c[110][30];
string str1[10010],str2[10010];
string tmp[10010];
int a[30],b[30];
char ans[110];
multiset<string>st;
multiset<string>::iterator it;
bool cmp(string x,string y){
	return x.length()<y.length();
}
void solve1(){
	cout<<"? "<<1<<" "<<n/2<<'\n';
	cout.flush();
	int siz1=0;
	for(int i=1;i<=((n>>1)*((n>>1)+1)>>1);++i){
		++siz1;
		cin>>str1[i];
		sort(str1[i].begin(),str1[i].end());
		st.insert(str1[i]);
	}
	cout<<"? "<<1<<" "<<n/2-1<<'\n';
	cout.flush();
	int siz2=0;
	for(int i=1;i<=((n>>1)*((n>>1)-1)>>1);++i){
		++siz2;
		cin>>str2[i];
		sort(str2[i].begin(),str2[i].end());
		it=st.find(str2[i]);
		st.erase(it);
	}
	int cnt=0;
	it=st.begin();
	while(it!=st.end()){
		tmp[++cnt]=(*it);++it;
	}
	sort(tmp+1,tmp+cnt+1,cmp);
	for(int i=1;i<=cnt;++i){
		for(int j=0;j<tmp[i].length();++j) ++b[tmp[i][j]-'a'+1];
		for(int j=1;j<=26;++j){
			if(b[j]!=a[j]) ans[(n>>1)-i+1]=j+'a'-1,a[j]=b[j];
			b[j]=0;
		}
	}
} 
void solve2(){
	cout<<"? "<<1<<" "<<n<<'\n';
	cout.flush();
	int siz=n*(n+1)>>1;
	for(int i=1;i<=siz;++i){
		cin>>str1[i];
		for(int j=0;j<str1[i].length();++j) ++c[str1[i].length()][str1[i][j]-'a'+1];
	}
	for(int k=(n>>1);k>=0;--k){
		for(int i=1;i<=26;++i) b[i]=c[k+1][i]-c[k][i];
		for(int i=k+1;i<=n-k-1;++i) if(ans[i]) --b[ans[i]-'a'+1];
		for(int i=1;i<=26;++i) if(b[i]) ans[n-k]=i+'a'-1;
	}
}
int main(){
	n=read();
	if(n<=3){
		if(n==1){
			printf("? 1 1\n");fflush(stdout);
			cin>>str1[1];
			cout<<"! "<<str1[1]<<'\n';
			cout.flush();
		}
		else if(n==2){
			printf("? 1 1\n");fflush(stdout);
			cin>>str1[1];
			printf("? 2 2\n");fflush(stdout);
			cin>>str2[1];
			cout<<"! "<<str1[1]+str2[1]<<'\n';
			cout.flush();
		}
		else{
			printf("? 1 1\n");fflush(stdout);
			cin>>str1[1];
			printf("? 2 2\n");fflush(stdout);
			cin>>str1[2];
			printf("? 3 3\n");fflush(stdout);
			cin>>str1[3];
			cout<<"! "<<str1[1]+str1[2]+str1[3]<<"\n";
			cout.flush();
		}
		return 0;
	}
	ios::sync_with_stdio(false);
	solve1();
	solve2();
	cout<<"! ";
	for(int i=1;i<=n;++i) cout<<ans[i];
	cout<<'\n';
	cout.flush();
}