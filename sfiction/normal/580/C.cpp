#include <cstdio>
#include <vector>

using namespace std;

const int MAXN = 1E5 + 10;

int n, m;
bool cat[MAXN];
vector<int> E[MAXN];

int ans;

void DFS(int u, int pre, int len){
	for (int i= 0; i < E[u].size(); ++i)
		if (E[u][i] != pre)
			DFS(E[u][i], u, !~len ? len : !cat[E[u][i]] ? 0 : len == m ? -1 : len + 1);
	ans += pre && E[u].size() == 1 && ~len;
}

int main(){
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &cat[i]);
	for (int u, v, i = 1; i < n; ++i){
		scanf("%d%d", &u, &v);
		E[u].push_back(v);
		E[v].push_back(u);
	}
	ans = 0;
	DFS(1, 0, cat[1]);
	printf("%d\n", ans);
	return 0;
}