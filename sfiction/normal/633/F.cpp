#include <cstdio>
#include <vector>

using namespace std;

typedef long long ll;

const int MAXN = 1E5 + 10;

int n;
int a[MAXN];
vector<int> E[MAXN];
ll ray[MAXN], ray2[MAXN], ray3[MAXN];
ll chain0[MAXN], chain[MAXN], chain2[MAXN];

ll ans = 0;

void DFS1(int u, int pre){
	ray[u] = ray2[u] = ray3[u] = 0;
	chain[u] = chain2[u] = 0;
	for (int v, i = 0; i < E[u].size(); ++i)
		if ((v = E[u][i]) != pre){
			DFS1(v, u);
			ll t = ray[v] + a[v];
			if (ray[u] < t)
				ray3[u] = ray2[u], ray2[u] = ray[u], ray[u] = t;
			else if (ray2[u] < t)
				ray3[u] = ray2[u], ray2[u] = t;
			else if (ray3[u] < t)
				ray3[u] = t;
			if (chain[u] < chain0[v])
				chain2[u] = chain[u], chain[u] = chain0[v];
			else if (chain2[u] < chain0[v])
				chain2[u] = chain0[v];
		}
	chain0[u] = max(chain[u], ray[u] + ray2[u] + a[u]);
}

void DFS2(int u, int pre, ll upRay, ll upChain){
	ans = max(ans, upChain + chain0[u]);
//	printf("%d, %I64d %I64d %I64d, %I64d %I64d %I64d\n%I64d %I64d, %I64d\n", u, chain0[u], chain[u], chain2[u], ray[u], ray2[u], ray3[u], upChain + chain0[u], upRay, upChain);
	for (int v, i = 0; i < E[u].size(); ++i)
		if ((v = E[u][i]) != pre){
			ll t = chain0[v] == chain[u] ? chain2[u] : chain[u];
			if (ray[v] + a[v] == ray[u])
				DFS2(v, u, max(upRay, ray2[u]) + a[u], max(max(upChain, t), a[u] + ray2[u] + max(upRay, ray3[u])));
			else
				DFS2(v, u, max(upRay, ray[u]) + a[u], max(max(upChain, t), a[u] + ray[u] + max(upRay, ray[v] + a[v] == ray2[u] ? ray3[u] : ray2[u])));
		}
}

int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	for (int u, v, i = 1; i < n; ++i){
		scanf("%d%d", &u, &v);
		E[u].push_back(v);
		E[v].push_back(u);
	}
	DFS1(1, 0);
	DFS2(1, 0, 0, 0);
	printf("%I64d\n", ans);
	return 0;
}