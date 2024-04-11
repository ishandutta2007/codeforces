#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;
typedef pair<int, int> ii;
int n;
vector<ii> a;
int gap[199999];
bool branch[199999];
bool truebranch[199999];
int dptable[199999];
int dp(int x) {
	if (x < -1) return -1000000000;
	if (x == -1) return 0;
	if (dptable[x] != -1) return dptable[x];
	if (dp(x - 1) < dp(x - 3) + gap[x]) branch[x] = true;
	return dptable[x] = max(dp(x - 1), dp(x - 3) + gap[x]);
}
void reconstruct(int x) {
	if (x < 0) return;
	if (branch[x] == true) {
		truebranch[x] = true;
		reconstruct(x - 3);
	} else reconstruct(x - 1);
}
int main() {
	fill_n(dptable, 199999, -1);
	fill_n(branch, 199999, false);
	fill_n(truebranch, 199999, false);
	int nextint;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &nextint);
		a.push_back(ii(nextint, i));
	}
	sort(a.begin(), a.end());
	for (int i = 1; i < n; ++i) gap[i - 1] = a[i].first - a[i - 1].first;
	int ans = -max(dp(n - 4), 0);
	reconstruct(n - 4);
	for (int i = 0; i < n - 1; ++i) ans += gap[i];
	printf("%d ", ans);
	int teams[n], cnt = 1;
	for (int i = 0; i < n - 1; ++i) {
		teams[a[i].second] = cnt;
		if (truebranch[i]) ++cnt;
	}
	teams[a[n - 1].second] = cnt;
	printf("%d\n", cnt);
	for (int i = 0; i < n; ++i) printf("%d ", teams[i]);
}