#include<bits/stdc++.h>
using namespace std;
#define int long long
int read(){
	int a=0,fh=1;char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')fh=-1;c=getchar();}
	while('0'<=c&&c<='9'){
		a=a*10+c-48;
		c=getchar();
	}
	return a*fh;
}
#define MN 200005
#define pii pair<int,int>
#define mp make_pair
#define x first
#define y second
int T,n,m;
int pw[MN];
char ch[MN];
int tax[55];
bool chk(int v){
	if(v<0)return 0;
	int h=0;
	for(int i=50;i;--i)tax[i]=tax[i-1];
	tax[0]=0;
	for(int i=0;i<=50;++i){
		if((v>>i)&1){
			if(h<pw[i]&&!tax[i]){
			//	cerr<<"GG1 "<<i<<endl;
				return 0;
			}
			if(tax[i])tax[i]--;
			else h-=pw[i];
		}
		h+=tax[i]*pw[i];
	}
	return 1;
}
signed main(){
	cin>>n>>T;
	scanf("%s",ch+1);
	pw[0]=1;for(int i=1;i<=50;++i)pw[i]=pw[i-1]*2;
	int tot=0;
	for(int i=1;i<=n;++i){
		ch[i]-='a';
		if(i!=n-1&&i!=n){
			tax[ch[i]]++;
			tot+=pw[ch[i]];
		}
	}
	int now=pw[ch[n]]-pw[ch[n-1]];
	T-=now;
	puts((chk(tot-abs(T)))?"Yes":"No");
	return 0;
}