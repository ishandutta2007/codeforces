#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;

int n,m,k;
vector< pair<int,int> > g[N],rg[N];
vector<int> vec[N];
int id[12][12],cnt[200];
int mp[200][200];

void build(){
	int tot=0;
	for(int i=1;i<=k;i++){
		for(int j=1;j<=i;j++){
			id[i][j]=++tot;
		}
	}
	for(int u=1;u<=n;u++){
		sort(g[u].begin(),g[u].end());
		for(int j=0;j<g[u].size();j++){
			int v=g[u][j].second;
			vec[v].push_back(id[g[u].size()][j+1]);
			cnt[id[g[u].size()][j+1]] ++;
		}
	}
	for(int i=1;i<=n;i++){
		sort(vec[i].begin(),vec[i].end());
		for(int j=1;j<vec[i].size();j++) if(vec[i][j]==vec[i][j-1]) mp[vec[i][j]][vec[i][j]]=1;
		vec[i].erase(unique(vec[i].begin(), vec[i].end()), vec[i].end());
		for(int x=0;x<vec[i].size();x++){
			for(int y=0;y<vec[i].size();y++){
				if(x==y)continue;
				mp[vec[i][x]][vec[i][y]]=1;
			}
		}
	}
}
int stk[12],val[12],ans=0;
void dfs(int now){
	if(now==k+1){
		//for(int i=1;i<=k;i++) printf("%d ", stk[i]); printf("\n");
		for(int i=1;i<=k;i++)val[i]=id[i][stk[i]];
		bool ok=1;
		for(int i=1;i<=k;i++)for(int j=1;j<=k;j++){
			if(mp[val[i]][val[j]]==1)ok=0;
		}
		int sum=0;
		for(int i=1;i<=k;i++) sum+=cnt[val[i]];
		if(sum!=n) ok=0;
		if(ok)ans++; 
		return;
	}
	for(int i=1;i<=now;i++) {
		stk[now]=i;
		dfs(now+1);
	}
}
int main() {
	scanf("%d%d%d",&n,&m,&k);
	// dfs(1);
	for(int i=1;i<=m;i++){
		int u,v,w;scanf("%d%d%d",&u,&v,&w);
		g[u].push_back(make_pair(w,v));
		rg[v].push_back(make_pair(w,u));
	}
	build();
	dfs(1);
	cout<<ans<<endl;
}