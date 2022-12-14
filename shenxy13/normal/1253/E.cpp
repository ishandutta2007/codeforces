#include <cstdio>
#include <algorithm>
#include <cstring>
#include <utility>
using namespace std;
typedef pair<int, int> ii;
const int INF = 1000000000;
int n, m;
ii posts[80];
int dptable[80][100000][2];
int dp(int id, int fur, bool cont) {
	if (fur >= m - 1) return 0;
	if (id == n) return INF;
	if (dptable[id][fur][cont] != -1) return dptable[id][fur][cont];
	if (!cont) {
		int del = dp(id + 1, fur, false);
		if (fur + 1 < posts[id].first - posts[id].second) {
			int ans = posts[id].first - posts[id].second - fur - 1;
			return dptable[id][fur][cont] = min(del, ans + dp(id, posts[id].first + posts[id].second + ans, true));
		} else if (fur > posts[id].first + posts[id].second) {
			int ans = fur - posts[id].first - posts[id].second;
			return dptable[id][fur][cont] = min(del, ans + dp(id, fur, true));
		} else {
			return dptable[id][fur][cont] = min(del, dp(id, posts[id].first + posts[id].second, true));
		}
	}
	return dptable[id][fur][cont] = min(dp(id, fur + 1, true) + 1, dp(id + 1, fur, false));
}
int main() {
	memset(dptable, -1, sizeof dptable);
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i) scanf("%d %d", &posts[i].first, &posts[i].second);
	for (int i = 0; i < n; ++i) --posts[i].first;
	sort(posts, posts + n);
	int ans = INF;
	for (int i = 0; i < n; ++i) ans = min(ans, dp(i, max(2 * posts[i].first, posts[i].first + posts[i].second), true) + max(0, posts[i].first - posts[i].second));
	printf("%d", ans);
	return 0;
}