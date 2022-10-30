#include <bits/stdc++.h>
using namespace std;
#define N 1010

typedef long long LL;

const LL inf = 1ll << 62;

int n, p[N], vis[N], runs;

void get_prime() {
	for (int i = 2; i < N; i ++) {
		if (vis[i]) continue;
		p[++runs] = i;
		for (int j = i * i; j < N; j += i) vis[j] = 1;
	}
}

LL multi(LL a, LL b) {
	if (a >= inf / b) return inf;
	return a * b;
}

LL LL_pow(LL a, int b) {
	LL rlt = 1, x = a;
	while (b) {
		if (b & 1) rlt = multi(rlt, x);
		x = multi(x, x), b >>= 1;
	}
	return rlt;
}

LL calc(int n, int mx, int now) {
	if (n == 1) return 1;
	LL rlt = inf;
	for (int i = 1; i <= mx; i ++) if (n % (i + 1) == 0) {
		rlt = min(rlt, multi(LL_pow(p[now], i), calc(n / (i + 1), i, now + 1)));
	}
	return rlt;
}

int main() {
//	freopen("e.in", "r", stdin);
	get_prime();
	cin >> n;
	cout << calc(n, n - 1, 1) << endl;
	return 0;
}
//27-e