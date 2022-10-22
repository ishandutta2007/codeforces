#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<set>
#include<vector>
#define PII pair<int,int>
#define pb push_back
#define ep emplace_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){ if(c=='-') f=-1; c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==1?x:-x;
}
inline void print(int x){
	if(x<0) putchar('-'),x=~x+1;
	if(x>=10) print(x/10);
	putchar((x%10)|48);
}
int n;
vector<int>vec[500010];
int siz[500010];
long long sum[500010];
void dfs1(int x,int f){
	siz[x]=1;
	for(int v:vec[x]){
		if(v==f) continue ;
		dfs1(v,x);
		siz[x]+=siz[v];
	}
}
void dfs2(int x,int f){
	for(int v:vec[x]){
		if(v==f) continue ;
		sum[v]=sum[x]+1ll*(siz[x]-siz[v])*siz[v];
		dfs2(v,x);
	}
}
int main(){
	n=read();
	for(int i=1;i<n;++i){
		int u=read(),v=read();
		vec[u].pb(v);vec[v].pb(u);
	}
	dfs1(1,1);
	dfs2(1,1);
	int rt=0;
	for(int i=1;i<=n;++i) if(sum[i]>sum[rt]) rt=i;
	dfs1(rt,rt);
	sum[rt]=1ll*n*(n-1)>>1;
	dfs2(rt,rt);
	long long ans=0;
	for(int i=1;i<=n;++i) ans=max(ans,sum[i]);
	printf("%lld\n",ans); 
}