#include <cstdio>
#include <vector>
#include <algorithm>
#pragma warning(disable : 4996)
using namespace std;
int n, m, z, c[25]; double r, dp[1048588], ret[25];
int main() {
	scanf("%d %d", &n, &m); z = n;
	vector<double> p;
	for (int i = 0; i < n; i++) {
		scanf("%lf", &r);
		if (r > 1.0e-9) c[i] = p.size(), p.push_back(r);
		else c[i] = -1;
	}
	n = p.size(); m = min(m, (int)p.size());
	dp[0] = 1.0;
	for (int i = 1; i < 1 << n; i++) {
		int cnt = 0;
		for (int j = 0; j < n; j++) {
			if (i & (1 << j)) {
				int s = i - (1 << j); cnt++;
				double sum = 1.0;
				for (int k = 0; k < n; k++) {
					if (s & (1 << k)) sum -= p[k];
				}
				dp[i] += dp[s] * p[j] / sum;
			}
		}
		if (cnt == m) {
			for (int j = 0; j < n; j++) {
				if (i & (1 << j)) ret[j] += dp[i];
			}
		}
	}
	for (int i = 0; i < z; i++) printf("%.12lf\n", c[i] == -1 ? 0.0 : ret[c[i]]);
	return 0;
}