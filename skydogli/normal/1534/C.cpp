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
#define MN 400005
#define pii pair<int,int>
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define vc vector<int>
#define Mod 1000000007
int T,n,m;
int a[MN],F[MN],b[MN],loc[MN];
char ch[MN];
int ans=1;
int Find(int a){
	if(F[a]==a)return a;
	return F[a]=Find(F[a]);
}
signed main(){
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;++i)F[i]=i;
		for(int i=1;i<=n;++i){
			a[i]=read();
			loc[a[i]]=i;
		}
		for(int i=1;i<=n;++i){
			b[i]=read();
			F[i]=Find(loc[b[i]]);
		}
		int ans=1;
		for(int i=1;i<=n;++i)if(Find(i)==i)ans=(ans*2)%Mod;
		printf("%lld\n",ans);
	}
	return 0;
}