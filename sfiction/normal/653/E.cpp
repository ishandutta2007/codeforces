#include <cstdio>
#include <set>
#include <vector>

using namespace std;

const int MAXN = 3E5 + 10;

int n, m, K;
vector<int> E[MAXN];
int G[MAXN];

int fa[MAXN], size[MAXN];

int find(int x){
	return x == fa[x] ? x : (fa[x] = find(fa[x]));
}

int main(){
	scanf("%d%d%d", &n, &m, &K);
	for (int u, v, i = 0; i < m; ++i){
		scanf("%d%d", &u, &v);
		if (u < v)
			swap(u, v);
		if (v == 1)
			G[u] = true;
		else
			E[u].push_back(v);
	}

	for (int i = 1; i <= n; ++i)
		fa[i] = i, size[i] = 1;
	set<int> A, B;
	for (int u = 2; u <= n; ++u){
		for (int i = 0; i < E[u].size(); ++i){
			int v = find(E[u][i]);
			if (--size[v] == 0){
				A.erase(v);
				B.insert(v);
			}
		}
		for (int i = 0; i < E[u].size(); ++i)
			++size[find(E[u][i])];

		for (auto p: A){
			size[u] += size[p];
			G[u] += G[p];
			fa[p] = u;
		}
		A.clear();
		A.swap(B);
		A.insert(u);
	}

	bool flag = true;
	int cnt = 0;
	for (auto p: A){
		G[p] = size[p] - G[p];
		if (G[p] == 0)
			flag = false;
		cnt += G[p];
	}
	puts(flag && A.size() <= K && K <= cnt ? "possible" : "impossible");

	return 0;
}