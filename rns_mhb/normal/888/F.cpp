#include <bits/stdc++.h>
using namespace std;
#define f0(i, a, b) for (int i = a; i < b; i ++)
#define f1(i, a, b) for (int i = a; i <= b; i ++)

#define N 505

const int mod = 1e9 + 7;
int n, a[N][N], b[2][N][N];

int func(int d, int st, int fs) {
    if (b[d][st][fs] >= 0) return b[d][st][fs];
    int &res = b[d][st][fs];
    if (st == fs) return res = 1;
    if (fs == st + 1) {
        res = d;
        if (d == 0) res = a[st][fs];
        return res;
    }
	res = 0;
    if (d == 1) {
        f0(i, st+1, fs) if (a[st][i]) res = (res + 1ll * func(1, st, i) * func(1, i, fs)) % mod;
        res = res + func(0, st+1, fs);
        if (res >= mod) res -= mod;
        return res;
    }
    f0(i, st+1, fs) if (a[st][i]) res = (res + 1ll * func(1, st, i) * func(0, i, fs)) % mod;
    if (a[st][fs]) {
		res = res + func(1, st, fs);
		if (res >= mod) res -= mod;
    }
    return res;
}

int main() {
    scanf("%d", &n);
    f1(i, 1, n) f1(j, 1, n) scanf("%d", &a[i][j]);
    memset(b, -1, sizeof b);
    int ans = func(0, 1, n);
    printf("%d\n", ans);
	return 0;
}