#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;
typedef long long ll;
constexpr ll MOD = 998244353;

ll pow2[300010];

int main() {
	pow2[0] = 1;
	for (int i = 1; i < 300010; ++i) pow2[i] = (pow2[i-1] << 1) % MOD;
	int t; scanf("%d", &t);
	while (t--) {
		int n, m; scanf("%d %d", &n, &m);
		vector<vector<int>> graph(n);
		for (int i = 0; i < m; ++i) {
			int u, v; scanf("%d %d", &u, &v);
			graph[--u].push_back(--v);
			graph[v].push_back(u);
		}
		vector<int> color(n, -1);
		int cclr = 0;
		bool isDiv = true;
		for (int i = 0; i < n; ++i) {
			if (color[i] == -1) {
				queue<int> q;
				color[i] = cclr;
				q.push(i);
				// printf("START C %d %d\n", i, color[i]);
				while (!q.empty()) {
					int cur = q.front(); q.pop();
					for (int next : graph[cur]) {
						if (color[next] == color[cur]) {
							// graph not bipartite
							isDiv = false;
							break;
						} else if (color[next] == -1) {
							// safely colorable
							color[next] = color[cur] ^ 1;
							// printf("COLOR %d %d\n", next, color[next]);
							q.push(next);
						}
					}
				}
				cclr += 2;
			}
		}
		if (!isDiv) {
			printf("0\n");
			continue;
		}
		// cclr/2 is the number of colors
		map<int, int> colorCounts;
		for (int i = 0; i < n; ++i) ++colorCounts[color[i]];
		ll ans = 1;
		for (int c = 0; c < cclr / 2; ++c) {
			ll factor = pow2[colorCounts[2*c]] + pow2[colorCounts[2*c + 1]];
			ans = (ans * factor) % MOD;
		}
		printf("%lld\n", ans);
	}
}