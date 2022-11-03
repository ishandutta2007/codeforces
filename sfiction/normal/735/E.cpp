#include <cstdio>
#include <algorithm>
#include <functional>
#include <numeric>
#include <vector>

using namespace std;

typedef long long ll;

const int MAXN = 1E2 + 10, MAXK = 20;
const int MOD = 1E9 + 7;

int n, K, m;
vector<int> E[MAXN];
int dp[MAXN][MAXK << 1 | 1];

void DFS(int u, int pre){
	fill_n(dp[u], m, 0);
	dp[u][0] = dp[u][K + 1] = 1;
	for (int v, i = 0; i < E[u].size(); ++i){
		if ((v = E[u][i]) == pre)
			continue;

		static int su[MAXK + 1 << 1], sv[MAXK + 1 << 1];
		auto m_sum = [](int a, int b){return (a + b) % MOD;};
		DFS(v, u);
		copy(dp[u], dp[u] + m, su + 1), partial_sum(su, su + m + 1, su, m_sum);
		copy(dp[v], dp[v] + m, sv + 1), partial_sum(sv, sv + m + 1, sv, m_sum);

		dp[u][0] = (ll)dp[u][0] * sv[m] % MOD;
		for (int j = 1; j <= K; ++j)
			dp[u][j] = ((ll)dp[u][j] * (sv[2 * K - j + 1] - sv[j - 1] + MOD)
					+ (ll)dp[v][j - 1] * (su[2 * K  - j + 2] - su[j + 1] + MOD)) % MOD;
		for (int j = K << 1; j > K; --j)
			dp[u][j] = ((ll)dp[u][j] * (sv[j] - sv[2 * K - j + 1] + MOD)
					+ (ll)dp[v][j - 1] * (su[j] - su[2 * K - j + 2] + MOD)) % MOD;
	}
}

int main(){
	scanf("%d%d", &n, &K);
	m = K << 1 | 1;
	for (int u, v, i = 1; i < n; ++i){
		scanf("%d%d", &u, &v);
		E[u].push_back(v);
		E[v].push_back(u);
	}
	DFS(1, 0);
	printf("%d\n", accumulate(dp[1], dp[1] + K + 1, 0ll) % MOD);
	return 0;
}