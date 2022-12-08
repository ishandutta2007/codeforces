#include<bits/stdc++.h>
#define sqr(x) (x)*(x)
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define vi vector<int>
#define pb push_back
#define ld long double
#define mp make_pair
#define pii pair<int,int>
#define pq priority_queue
#define rf random_shuffle
#define np next_permutation
#define lb lower_bound
#define debuge cerr<<"isok"<<endl
#define debug(x) cout<<#x<<"="<<x<<endl
#define SS second
#define FF first
#define file(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout)
#define nowtime cerr<<"time:"<<(ll)clock()*1000/CLOCKS_PER_SEC<<endl
using namespace std;
inline void read(int &x){
	x=0;char ch=getchar(),flag=0;
	while((ch>'9'||ch<'0')&&ch!='-') ch=getchar();
	if(ch=='-') flag=1,ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	if(flag) x=-x;
}
inline void read(int &x,int &y){read(x),read(y);}
inline void read(int &x,int &y,int &z){read(x),read(y),read(z);}

const int N=300005;
set<int> s[N];
int p,mod,n,m,pw[N],si[N],h[N],tot,a[N];
char str[N];

inline int get(int x,int y){
	int t=h[y]-(ll)h[x-1]*pw[y-x+1]%mod;
	if(t<0) t+=mod;
	return t;
}
inline int r(){
	return rand()%1000+1;
}
inline int ran(){
	return r()*1000000+r()*1000+r();
}
inline bool check(int x){
	for(int i=2;i*i<=x;i++)
		if(x%i==0) return 0;
	return 1;
}

int main(){
#ifndef ONLINE_JUDGE
	int ss=0,sum=0;
	for(int i=1;i<=100000;i++){
		int t=i;
		ss+=i;sum++;
		if(ss>300000) break;
		while(t%2==0){
			ss+=i,sum++;
			if(ss>300000)break;
			t/=2;
		}if(ss>300000) break;
	}
	printf("%d\n",sum);
#endif
	srand(time(0));
	scanf("%d",&n);
	do{
		p=ran()%1001+29;
	}while(!check(p));
	do{
		mod=ran()%200000000+1000000000;
	}while(!check(mod));
	pw[0]=1;
	for(int i=1;i<=N-5;i++) pw[i]=(ll)pw[i-1]*p%mod;
	for(int i=1;i<=n;i++){
		int typ;
//		debug(i);
		scanf("%d%s",&typ,str+1);
		m=strlen(str+1);
		for(int j=1;j<=m;j++)
			h[j]=((ll)h[j-1]*p%mod+str[j]-'a'+1)%mod;
		if(typ==3){
			int ans=0;tot=0;
			for(int j=1;j<=m;j++){
				if(si[j]<=0) continue;
				for(int k=1;k<=m-j+1;k++)
					if(s[j].count(get(k,k+j-1))) ans++;
			}
			printf("%d\n",ans);
		}
		else if(typ==1){
			s[m].insert(h[m]);
			si[m]++;
		}
		else{
			s[m].erase(h[m]);
			si[m]--;
		}
		fflush(stdout);
	}
	return 0;
}
/*
10
1 abc
1 bcd
1 abcd
3 abcd
2 abcd
3 abcd
2 bcd
3 abcd
2 abc
3 abcd
*/