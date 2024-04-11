#include<cstdio>
#include<map>
#include<unordered_map>
#define map unordered_map
#include<set>
#include<iostream>
typedef long long ll;
const int maxn = 2001;
const int mod = 1e9 + 7;
typedef std::pair<int,int> PIL;
std::map<int,int> f[maxn][20],g[20];
int n,m;
struct T{
	struct T2{
		int to,nxt;
	}way[maxn<<1];
	int h[maxn],num;
	inline void adde(int x,int y){
		way[++num]={x,h[y]},h[y]=num;
		way[++num]={y,h[x]},h[x]=num;
	}
	inline void merge(std::map<int,int>&res,std::map<int,int>&x,std::map<int,int>&y){
		for(PIL i:x)
			for(PIL j:y)
		(res[i.first+j.first*1293701]+=(ll)i.second*j.second%mod)%=mod;
	}
	inline void dp(int x){
		vis[x]=1;
		for(int i=h[x];i;i=way[i].nxt)
			if(!vis[way[i].to])dp(way[i].to);
		f[x][1][2]=1;
		for(int i=h[x];i;i=way[i].nxt)
			if(!vis[way[i].to]){
				for(int j=1;j<=m;++j){
					for(int k=1;k+j<=m;++k){
						merge(g[j+k],f[x][j],f[way[i].to][k]);
					}
				}
				for(int j=1;j<=m;++j){
					for(PIL k:g[j])	(f[x][j][k.first] += k.second)%=mod;
					g[j].clear();	
				}
			}
		for(int j=1;j<=m;++j){
			g[j].swap(f[x][j]);
			for(PIL k:g[j])	(f[x][j][k.first^j*315+21352135]+=k.second)%=mod;
			g[j].clear();	
		}
		vis[x]=0;
	}
	int vis[maxn],size[maxn];
	inline int gethash(int x){
		vis[x]=size[x]=1;
		int a=2;
		for(int i=h[x];i;i=way[i].nxt)
			if(!vis[way[i].to])
				a += gethash(way[i].to)*1293701,size[x]+=size[way[i].to];
		a ^= size[x]*315 + 21352135;
		vis[x]=0;
		return a;
	}
}g1,g2;
std::set<int> s;
int main(){
	std::ios::sync_with_stdio(false),std::cin.tie(0);
	std::cin >> n;
	for(int i=1,x,y;i<n;++i)std::cin >> x >> y,g1.adde(x,y);
	std::cin >> m;
	for(int i=1,x,y;i<m;++i)std::cin >> x >> y,g2.adde(x,y);
	for(int i=1;i<=m;++i)s.insert(g2.gethash(i));
	g1.dp(1);
	int ans=0;
	for(int i:s){
		for(int j=1;j<=n;++j)
			(ans += f[j][m][i])%=mod;
	}
	printf("%d\n",ans);
}