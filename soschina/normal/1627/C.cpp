#include <cstdio>
#include <vector>
using namespace std;
const int N = 1e5 + 1;

int t, n, u, v;
struct edge{
	int id, to;
	edge(int _id, int _to) : id(_id), to(_to) {}
};
vector<edge> e[N];

int ans[N];

void dfs(int i, int from){
	int lastnum;
	for(edge ed : e[i])
		if(ed.id == from)
			lastnum = ans[ed.id];
	for(edge ed : e[i])
		if(ed.id != from){
			ans[ed.id] = lastnum == 2 ? 5 : 2;
			dfs(ed.to, ed.id);
		}
}

int main(){
	scanf("%d", &t);
	while(t--){
		for(int i = 1; i <= n; i++)
			e[i].clear();
		scanf("%d", &n);
		for(int i = 1; i < n; i++){
			scanf("%d%d", &u, &v);
			e[u].push_back(edge(i, v));
			e[v].push_back(edge(i, u));
		}
		bool notstr = false;
		for(int i = 1; i <= n; i++)
			if(e[i].size() > 2) notstr = true;
		if(notstr){
			puts("-1");
			continue;
		}
		for(int i = 1; i <= n; i++)
			if(e[i].size() == 1){
				ans[e[i][0].id] = 2;
				dfs(e[i][0].to, e[i][0].id);
				break;
			}
		for(int i = 1; i < n; i++)
			printf("%d ", ans[i]);
		putchar('\n');
	}
	return 0;
}