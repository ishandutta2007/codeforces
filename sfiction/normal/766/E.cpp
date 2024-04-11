#include <bits/stdc++.h>

#define debug(x) cout << #x" = " << x;

#define st first
#define nd second

using namespace std;
using namespace placeholders;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;

const int MAXN = 1E6 + 10, D = 20;

int n;
int a[MAXN];
vector<int> E[MAXN];
int size[MAXN];
int cnt[MAXN][D];
ll tot[D];

void DFS(int u, int pre){
	size[u] = 1;
	for (int v: E[u]){
		if (v == pre)
			continue;
		DFS(v, u);
		for (int i = 0; i < D; ++i){
			tot[i] += a[u] >> i & 1 ? 1ll * cnt[u][i] * cnt[v][i] + 1ll * (size[u] - cnt[u][i]) * (size[v] - cnt[v][i])
							: 1ll * cnt[u][i] * (size[v] - cnt[v][i]) + 1ll * (size[u] - cnt[u][i]) * cnt[v][i];
			cnt[u][i] += cnt[v][i];
		}
		size[u] += size[v];
	}
	for (int i = 0; i < D; ++i)
		if (a[u] >> i & 1)
			cnt[u][i] = size[u] - cnt[u][i];
}

int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", a + i);
	for (int u, v, i = 1; i < n; ++i){
		scanf("%d%d", &u, &v);
		E[u].push_back(v);
		E[v].push_back(u);
	}
	DFS(1, 0);
	ll ans = 0;
	for (int i = D - 1; i >= 0; --i)
		ans = (ans << 1) + tot[i];
	printf("%lld\n", ans + accumulate(a + 1, a + n + 1, 0ll));
	return 0;
}