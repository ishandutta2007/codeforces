#include <bits/stdc++.h>
using namespace std;
#define N 1001001

typedef long long LL;

LL m, e[N];
int f[N];

inline int SQRT3(LL m) {
	int k = lower_bound(e + 1, e + 100000 + 1, m + 1) - e - 1;
	return k;
}

int calc(LL m) {
	if (!m) return 0;
	int mx = SQRT3(m);
	int rlt = calc(m - e[mx]) + 1;
	if (f[mx] > rlt) {
		rlt = f[mx];
	}
	return rlt;
}

LL chk(LL m) {
	if (!m) return 0;
	int mx = SQRT3(m);
	int len = calc(m - e[mx]) + 1;
	LL rlt = chk(m - e[mx]) + e[mx];
	if (f[mx] > len) {
		rlt = chk(e[mx] - 1);
	}
	return rlt;
}

void prepare() {
	for (int i = 1; i <= 100000; i ++) e[i] = 1ll * i * i * i;
	f[1] = 0;
	for (int i = 2; i <= 100000; i ++) f[i] = calc(e[i] - 1);
}

int main() {
//	freopen("b.in", "r", stdin);
	prepare();
	cin >> m;
	int ans = calc(m);
	LL x = chk(m);
	cout << ans << ' ' << x << endl;
	return 0;
}