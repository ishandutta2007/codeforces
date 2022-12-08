#include <bits/stdc++.h>

using namespace std;

int d[200005];
int n;
int a[200005];
map<int, int> mp;

int lowbit(int x) {
	return x & -x;
}

void upd(int x, int k) {
	for (int i = x; i <= n; i += lowbit(i))
		d[i] += k;
}

int sum(int x) {
	int r = 0;
	for (int i = x; i > 0; i -= lowbit(i))
		r += d[i];
	return r;
}

bool exist(int x) {
	return sum(x) - sum(x - 1);
}

void solve() {
	mp.clear();
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		mp[a[i]];
	}
	int cnt = 0;
	for (auto &i : mp) {
		i.second = ++cnt;
	}
	int l = 0;
	int r = 0;
	upd(mp[a[0]], 1);
	for (int i = 1; i < n; ++i) {
		if (exist(mp[a[i]])) {
			int ll = sum(mp[a[i]] - 1);
			int rr = sum(n) - sum(mp[a[i]]);
			if (abs(l + ll - r - rr) > 2) {
				printf("NO\n");
				return;
			}
			if (l + ll < r + rr) {
				l += 2;
			} else if (l + ll > r + rr) {
				r += 2;
			} else {
				++l;
				++r;
			}
		} else {
			int ll = sum(mp[a[i]] - 1);
			int rr = sum(n) - sum(mp[a[i]]);
			if (abs(l + ll - r - rr) > 1) {
				printf("NO\n");
				return;
			}
			if (l + ll < r + rr) {
				++l;
			} else {
				++r;
			}
			upd(mp[a[i]], 1);
		}
	}
	printf("YES\n");
}

int main() {
//	freopen("in.txt", "r", stdin);
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
		memset(d, 0, sizeof(int) * (n + 5));
	}
	return 0;
}