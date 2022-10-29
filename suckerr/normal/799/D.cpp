#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 7;

int a, b, h, w, n;
int f[N];

int fuck(int a, int b, int h, int w) {
	int A = (a <= h ? 1 : (a + h - 1) / h);
	int B = (b <= w ? 1 : (b + w - 1) / w);
	if (A == 1 && B == 1) return 0;
	// cout << A << " " << B << endl;
	set<pair<int, int>> cur, nxt;
	cur.insert({A, B});
	for (int i = 0; i < n; i++) {
		nxt.clear();
		for (auto t : cur) {
			if (t.first > 1) nxt.insert({max(1, (t.first + f[i] - 1) / f[i]), t.second});
			if (t.second > 1) nxt.insert({t.first, max(1, (t.second + f[i] - 1) / f[i])});
		}
		swap(nxt, cur);
		for (auto t : cur) {
			if (t == make_pair(1, 1)) return i + 1;
		}
	}
	return n + 1;
}

int main() {
	scanf("%d %d %d %d %d", &a, &b, &h, &w, &n);
	for (int i = 0; i < n; i++) scanf("%d", &f[i]);
	sort(f, f + n);
	reverse(f, f + n);
	int ans = n + 1;
	ans = min(ans, fuck(a, b, h, w));
	ans = min(ans, fuck(b, a, h, w));
	if (ans > n) {
		puts("-1");
	} else {
		printf("%d\n", ans);
	}
	return 0;
}