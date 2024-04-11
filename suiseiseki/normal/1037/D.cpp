#include <cstdio>
#include <vector>
#include <set>
#include <queue>
using namespace std;
int n;
vector<int> ng[200005];
set<int> g[200005];
int fa[200005];
void dfs_1(int x){
	for(unsigned int i=0;i<ng[x].size();i++){
		if(ng[x][i]==fa[x]){
			continue;
		}
		fa[ng[x][i]]=x;
		g[x].insert(ng[x][i]);
		dfs_1(ng[x][i]);
	}
}
queue<int> q;
bool use[200005];
int main(){
	scanf("%d",&n);
	int u,v;
	for(int i=1;i<n;i++){
		scanf("%d%d",&u,&v);
		ng[u].push_back(v);
		ng[v].push_back(u);
	}
	dfs_1(1);
	int a;
	scanf("%d",&a);
	if(a!=1){
		puts("No");
		return 0;
	}
	q.push(a);
	int x;
	use[a]=1;
	while(!q.empty()){
		x=q.front();
		q.pop();
		for(unsigned int i=0;i<g[x].size();i++){
			scanf("%d",&a);
			if(g[x].find(a)==g[x].end()||use[a]){
				puts("No");
				return 0;
			}
			use[a]=1;
			q.push(a);
		}
	}
	puts("Yes");
	return 0;
}