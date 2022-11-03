#include <cstdio>
#include <utility>
#include <vector>

#define st first
#define nd second

using namespace std;

typedef pair<int, int> PII;

const int MAXN = 2E5 + 10;

int n;
vector<PII> E[MAXN];
vector<vector<int> > ans;

void DFS(int u, int pre, int lastC){
	int c = -1;
	for (int i = 0; i < E[u].size(); ++i)
		if (E[u][i].st != pre){
			if (++c == lastC)
				++c;
			if (ans.size() <= c)
				ans.push_back(vector<int>());
			ans[c].push_back(E[u][i].nd);
			DFS(E[u][i].st, u, c);
		}
}

int main(){
	scanf("%d", &n);
	for (int u, v, i = 1; i < n; ++i){
		scanf("%d%d", &u, &v);
		E[u].push_back(PII(v, i));
		E[v].push_back(PII(u, i));
	}
	DFS(1, 0, -1);
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); ++i){
		printf("%d", ans[i].size());
		for (int j = 0; j < ans[i].size(); ++j)
			printf(" %d", ans[i][j]);
		puts("");
	}
	return 0;
}