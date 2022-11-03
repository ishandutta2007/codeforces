#include <cstdio>
#include <vector>

using namespace std;

const int MAXN = 1E5 + 10;

int n, m;
int a[MAXN];
vector<int> E[MAXN];
bool nrt[MAXN];

vector<int> ans;
bool ansFlag;

void DFS(int u, int p){
	for (int v, i = 0; i < E[u].size(); ++i)
		if ((v = E[u][i]) != p){
			ansFlag &= a[v] == a[u] || a[v] == v;
			DFS(v, u);
		}
	if (u == a[u])
		ans.push_back(a[u]);
}

int main(){
	scanf("%d%d", &n, &m);
	for (int u, v, i = 0; i < m; ++i){
		scanf("%d%d", &u, &v);
		E[u].push_back(v);
		E[v].push_back(u);
		nrt[v] = true;
	}
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);

	ansFlag = true;
	for (int i = 1; i <= n; ++i)
		if (!nrt[i])
			DFS(i, 0);

	if (ansFlag){
		printf("%d\n", (int)ans.size());
		for (int i = 0; i < ans.size(); ++i)
			printf("%d\n", ans[i]);
	}
	else
		puts("-1");
	return 0;
}