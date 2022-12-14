#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <cassert>
using namespace std;
int a[1000];
inline int mex(int n) {
	int cnt[n + 1];
	fill_n(cnt, n + 1, 0);
	for (int i = 0; i < n; ++i) ++cnt[a[i]];
	for (int i = 0; i < n; ++i) {
		if (cnt[i] == 0) return i;
	}
	return n;
}
int main() {
	int t;
	scanf("%d", &t);
	for (int h = 0; h < t; ++h) {
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
		vector<int> ans;
		set<int> unsettled;
		for (int i = 0; i < n; ++i) {
			if (a[i] != i) unsettled.insert(i);
		}
		while (!unsettled.empty()) {
			int x = mex(n);
			if (x == n) {
				int k = *unsettled.begin();
				ans.push_back(k);
				a[k] = n;
			} else ans.push_back(x), unsettled.erase(x), a[x] = x;
		}
		assert(ans.size() <= 2 * n);
		printf("%lu\n", ans.size());
		if (ans.size() != 0) printf("%d", ans[0] + 1);
		for (int i = 1; i < ans.size(); ++i) printf(" %d", ans[i] + 1);
		printf("\n");
	}
	return 0;
}