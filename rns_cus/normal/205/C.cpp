#include <bits/stdc++.h>
using namespace std;
#define N 22

typedef long long LL;

LL ex[N], f[N], l, r;
int cnt, a[N];

LL calc(LL x) {
	if (x <= 9) return x;
	if (x <= 99) {
		LL rlt = 9;
		for (int i = 1; i <= 9; i ++) {
			if (x >= i * 10 + i) rlt ++;
		}
		return rlt;
	}
	cnt = 0;
	while (x) a[++cnt] = x % 10, x /= 10;
	LL y = 0;
	for (int i = cnt - 1; i > 1; i --) y = y * 10 + a[i];
	LL rlt = f[cnt-1] + ex[cnt-2] * (a[cnt] - 1);
	rlt += y;
	if (a[1] >= a[cnt]) rlt ++;
	return rlt;
}

void prepare() {
	ex[0] = 1;
	for (int i = 1; i <= 18; i ++) ex[i] = ex[i-1] * 10;
	f[1] = 9;
	for (int i = 2; i <= 18; i ++) {
        f[i] = f[i-1] + 9 * ex[i-2];
	}
}

int main() {
//	freopen("c.in", "r", stdin);
	prepare();
	cin >> l >> r;
	cout << calc(r) - calc(l - 1) << endl;
	return 0;
}