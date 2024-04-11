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
int a[MN],F[MN];
int x[MN],y[MN],vis[MN];
char ch[MN];
int Find(int a){
	if(F[a]==a)return a;
	return F[a]=Find(F[a]);
}
signed main(){
	T=read();
	while(T--){
		int n=read();m=read();
		for(int i=1;i<=n;++i)vis[i]=0;
		for(int i=1;i<=n;++i)F[i]=i;
		int cnt=0;
		for(int i=1;i<=m;++i){
			x[i]=read();y[i]=read();
			if(x[i]!=y[i]){vis[y[i]]=1;cnt++;}
		}
		for(int i=1;i<=m;++i){
			if(x[i]!=y[i]){
				if(Find(x[i])==Find(y[i]))cnt++;
				F[Find(x[i])]=Find(y[i]);
			}
		}
		printf("%lld\n",cnt);
	}
	return 0;
}