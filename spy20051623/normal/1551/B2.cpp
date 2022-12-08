#include<bits/stdc++.h>

using namespace std;
#define mm(a) memset(a,0,sizeof(a))
#define rep(i, a, b) for(int i=(a);i<=(b);i++)
const int Maxx = 2 * 1e5 + 22;
int ans[Maxx];
unordered_map<int, vector<int>> a;

void solve() {
	int n, k;
	scanf("%d%d", &n, &k);
	mm(ans);
	int tmp;
	rep(i, 1, n) {
		scanf("%d", &tmp);
		a[tmp].push_back(i);
	}
	for (int i = 1; i <= n; i++) {
		if (a[i].size() >= k) {
			for (int j = 0; j < k; j++) {
				ans[a[i][j]] = j + 1;
			}
		}
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i].size() < k) cnt += a[i].size();
	}
	cnt = cnt / k * k;
	int now = 0;
	for (int i = 1; i <= n; i++) {
		if (now == cnt) break;
		if (a[i].size() < k) {
			for (int j : a[i]) {
				++now;
				ans[j] = now % k + 1;
				if (now == cnt) break;
			}
		}
	}
	rep(i, 1, n) printf("%d ", ans[i]);
	printf("\n");
	a.clear();
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}