#include <bitset>
#include <cstdio>
#include <vector>
#pragma warning(disable : 4996)
using namespace std;
const int lim = 1000009;
int solvemax(vector<int> cs, int m) {
	int pa = 0, pb = 0;
	for (int i = 0; i < cs.size(); ++i) {
		pa += cs[i] / 2;
		pb += cs[i] % 2;
	}
	if (m <= pa) return 2 * m;
	if (m <= pa + pb) return 2 * pa + (m - pa);
	return 2 * pa + pb;
}
int solvemin(vector<int> cs, int m) {
	bitset<lim> dp = 1;
	int threshold = 100;
	vector<int> cnt(threshold);
	for (int i : cs) {
		if(i >= threshold) dp |= dp << i;
		else ++cnt[i];
	}
	vector<bool> dpx(lim);
	for (int i = 0; i < lim; ++i) {
		if (dp[i]) dpx[i] = true;
	}
	for (int i = 1; i < threshold; ++i) {
		vector<int> s(lim);
		for (int j = 0; j < lim; ++j) {
			s[j] = (dpx[j] ? 1 : 0) + (j >= i ? s[j - i] : 0);
			if (j >= (cnt[i] + 1) * i) s[j] -= (dpx[j - (cnt[i] + 1) * i] ? 1 : 0);
		}
		for (int j = 0; j < lim; ++j) {
			if (s[j] != 0) dpx[j] = true;
		}
	}
	return dpx[m] ? m : m + 1;
}
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	vector<int> p(n);
	for (int i = 0; i < n; ++i) scanf("%d", &p[i]), --p[i];
	vector<int> cs;
	vector<bool> vis(n, false);
	for (int i = 0; i < n; ++i) {
		if (vis[i]) continue;
		int sz = 0, pos = i;
		while (!vis[pos]) {
			++sz;
			vis[pos] = true;
			pos = p[pos];
		}
		cs.push_back(sz);
	}
	int mn = solvemin(cs, m);
	int mx = solvemax(cs, m);
	printf("%d %d\n", mn, mx);
	return 0;
}