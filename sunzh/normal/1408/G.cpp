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
int m;
int cnt;
struct node{
	int u,v,w;
	bool operator <(const node &x) const {
		return w<x.w; 
	}
}e[3000010];
int fa[3010];
int siz[3010];
int sz[3010];
vector<int>vec[3010];
int tin[3010],tout[3010];
int idx;
vector<int>f[3010];
int dp[3010][3010];
const int mod=998244353;
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
void dfs(int x){
	tin[x]=idx+1;
	if(x<=n) ++idx;
	for(auto v:vec[x]) dfs(v);
	tout[x]=idx;
	if((siz[x]*(siz[x]-1)>>1)==sz[x]) f[tout[x]].pb(tin[x]-1);
}
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			int x=read();
			if(i<j) e[++m].u=i,e[m].v=j,e[m].w=x;
		}
	}
	sort(e+1,e+m+1);
	for(int i=1;i<=n;++i) fa[i]=i,siz[i]=1;
	cnt=n;
	for(int i=1;i<=m;++i){
		int fx=find(e[i].u);
		int fy=find(e[i].v);
		if(fx==fy){
			++sz[fx];continue ;
		}
		++cnt;
		fa[fx]=fa[fy]=fa[cnt]=cnt;
		vec[cnt].pb(fx);vec[cnt].pb(fy);
		siz[cnt]=siz[fx]+siz[fy];
		sz[cnt]=sz[fx]+sz[fy]+1;
	}
	dfs(cnt);
	dp[0][0]=1;
	for(int i=1;i<=idx;++i){
		for(int j:f[i]){
			for(int k=1;k<=i&&k<=j+1;++k) (dp[i][k]+=dp[j][k-1])%=mod;
		}
	}
	for(int i=1;i<=n;++i) printf("%d ",dp[idx][i]);
}