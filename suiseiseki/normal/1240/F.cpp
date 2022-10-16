#include <map>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const int Maxn=1000000;
const int Inf=0x3f3f3f3f;
int n,m,k;
pair<int,int> edge[Maxn+5];
int a[Maxn+5];
map<pair<int,int>,int> mp;
int deg[Maxn+5],sz[Maxn+5],st[Maxn+5],col[Maxn+5];
vector<pair<int,int> > g[Maxn+5];
int ans[Maxn+5];
void match(int u,int fa,int from,int to){
	for(int i=0;i<(int)g[u].size();i++){
		if(g[u][i].first==from){
			g[u][i].first=to;
			match(g[u][i].second,u,to,from);
		}
	}
	for(int i=0;i<(int)g[u].size();i++){
		if(g[u][i].second==fa){
			g[u][i].first=from;
		}
	}
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++){
		scanf("%*d");
	}
	for(int i=1;i<=m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		if(u>v){
			swap(u,v);
		}
		edge[i]=make_pair(u,v+n);
		deg[u]++;
		deg[v+n]++;
	}
	n=(n<<1);
	st[0]=1;
	for(int i=1;i<=n;i++){
		sz[i]=(deg[i]-1)/k+1;
		st[i]=st[i-1]+sz[i-1];
	}
	for(int i=1;i<=m;i++){
		int u=edge[i].first,v=edge[i].second;
		g[st[u]].push_back(make_pair(Inf,st[v]));
		g[st[v]].push_back(make_pair(Inf,st[u]));
		edge[i]=make_pair(st[u],st[v]);
		mp[edge[i]]=i;
		col[u]++;
		col[v]++;
		if(col[u]==k){
			st[u]++;
			col[u]=0;
		}
		if(col[v]==k){
			st[v]++;
			col[v]=0;
		}
	}
	for(int i=1;i<=m;i++){
		int u=edge[i].first,v=edge[i].second;
		int pos_u=0,pos_v=0;
		sort(g[u].begin(),g[u].end());
		sort(g[v].begin(),g[v].end());
		for(int j=0;j<(int)g[u].size();j++){
			if(j+1!=g[u][j].first){
				pos_u=j+1;
				break;
			}
		}
		for(int j=0;j<(int)g[v].size();j++){
			if(j+1!=g[v][j].first){
				pos_v=j+1;
				break;
			}
		}
		for(int j=0;j<(int)g[u].size();j++){
			if(g[u][j].second==v){
				g[u][j].first=pos_u;
			}
		}
		match(v,u,pos_u,pos_v);
	}
	for(int i=1;i<=st[n];i++){
		for(int j=0;j<(int)g[i].size();j++){
			if(i<g[i][j].second){
				ans[mp[make_pair(i,g[i][j].second)]]=g[i][j].first;
			}
		}
	}
	for(int i=1;i<=m;i++){
		printf("%d\n",ans[i]);
	}
	return 0;
}