#include <bits/stdc++.h>
using namespace std;
#define N 55

typedef long long LL;

int n, a[N];
LL k, f[N][2][2];

LL calc(int l, int r, int rev, int inv) {
	if (l > r) return 1;
	if (f[l][rev][inv] != -1) return f[l][rev][inv];
	f[l][rev][inv] = 0;
	for (int i = 0; i <= 1; i ++) {
		for (int j = 0; j <= 1; j ++) {
			if (a[l] != -1 && a[l] != i || a[r] != -1 && a[r] != j) continue;
			if (l == r && i != j) continue;
			if (!rev && i > j) continue;
			if (!inv && i > !j) continue;
			f[l][rev][inv] += calc(l + 1, r - 1, rev || (i < j), inv || (i < !j));
		}
	}
	return f[l][rev][inv];
}

int main() {
//	freopen("e.in", "r", stdin);
	cin >> n >> k; k ++;
	memset(a, -1, sizeof a);
	a[1] = 0;
	memset(f, -1, sizeof f);
	if (calc(1, n, 0, 0) < k) {
		puts("-1"); return 0;
	}
	for (int i = 2; i <= n; i ++) {
		a[i] = 0;
		memset(f, -1, sizeof f);
		LL rlt = calc(1, n, 0, 0);
		if (k > rlt) k -= rlt, a[i] = 1;
	}
	for (int i = 1; i <= n; i ++) cout << a[i]; cout << endl;
	return 0;
}