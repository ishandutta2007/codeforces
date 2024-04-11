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
#define pb push_back
#define vc vector
int T,n,m;
int a[MN];
int dep[MN],fa[MN],f[MN],mx[MN],mn[MN];
vector<int>e[MN],p[MN];
void dfs(int x){
	p[dep[x]].pb(x);
	mx[dep[x]]=max(mx[dep[x]],a[x]);
	mn[dep[x]]=min(mn[dep[x]],a[x]);
	for(auto v:e[x]){
		if(fa[x]==v)continue;
		fa[v]=x;dep[v]=dep[x]+1;dfs(v);
	}
}
const int inf=1e18;
signed main(){
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;++i)f[i]=0,e[i].clear(),p[i].clear(),mx[i]=-1e18,mn[i]=1e18;
		for(int i=2;i<=n;++i){
			int v=read();
			e[i].pb(v);e[v].pb(i);
		}
		for(int i=2;i<=n;++i)a[i]=read();
		dep[1]=1;dfs(1);
		int m1=-inf,m2=-inf;
		for(int i=n;i;--i){
			int mm1=-inf,mm2=-inf;
			for(auto x:p[i]){
				f[x]=max(a[x]+m1,f[x]);
				f[x]=max(m2-a[x],f[x]);
				f[x]=max(f[x],a[x]-mn[i]);
				f[x]=max(f[x],mx[i]-a[x]);
				for(auto v:e[x]){
					if(fa[x]==v)continue;
					f[x]=max(f[x],f[v]+a[x]-mn[i]);
					f[x]=max(f[x],f[v]+mx[i]-a[x]);
				}
				mm1=max(mm1,f[x]-a[fa[x]]);
				mm2=max(mm2,f[x]+a[fa[x]]);
			}
			m1=mm1;m2=mm2;
		}
		printf("%lld\n",f[1]);
	}
	return 0;
}