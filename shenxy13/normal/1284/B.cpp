#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> ii;
int main() {
	int n, l, x;
	scanf("%d", &n);
	vector<int> s[n];
	for (int i = 0; i < n; ++i) {
		scanf("%d", &l);
		for (int j = 0; j < l; ++j) {
			scanf("%d", &x);
			s[i].push_back(x);
		}
	}
	bool impt[n];
	int mn[n], mx[n];
	fill_n(impt, n, false);
	fill_n(mn, n, 1000001);
	fill_n(mx, n, -1);
	vector<ii> minimax;
	long long ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < s[i].size(); ++j) {
			if (j != 0) {
				if (s[i][j] > s[i][j - 1]) impt[i] = true;
			}
			mn[i] = min(mn[i], s[i][j]);
			mx[i] = max(mx[i], s[i][j]);
		}
		if (!impt[i]) minimax.push_back(ii(mn[i], mx[i]));
	}
	int cnt = n;
	for (int i = 0; i < n; ++i) {
		if (impt[i]) --cnt, ans += 2 * cnt + 1;
	}
	sort(minimax.begin(), minimax.end());
	for (ii i: minimax) {
		ans += lower_bound(minimax.begin(), minimax.end(), ii(i.second, -1)) - minimax.begin();
	}
	printf("%lld", ans);
	return 0;
}