#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f1(i, a, b) for (int i = a; i <= b; i ++)

const int inf = 0x3f3f3f3f;
const ll linf = 2e18 + 100;

#define N 200005

int n;
ll a[N], K;

struct mat {
    ll a[11][11];
    int n;
    mat() {}
    mat(int _n) {n = _n; memset(a, 0, sizeof a);}
    mat(int _n, ll x) {
        n = _n;
        memset(a, 0, sizeof a);
        f1(i, 1, n) a[i][i] = x;
    }
    mat operator * (const mat &x) const {
        mat res = mat(n);
        for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= n; j ++)
		for (int k = 1; k <= n; k ++) {
            if (!a[i][k]) continue;
			if (x.a[k][j] > K / a[i][k]) {
                res.a[n][1] = K;
                return res;
			}
            res.a[i][j] += a[i][k] * x.a[k][j];
            if (res.a[i][j] >= K) {
				res.a[n][1] = K;
				return res;
            }
		}
        return res;
    }
    bool ok() {return a[n][1] >= K;}
    void init(int _n) {n = _n; memset(a, 0, sizeof a);}
    void print() {
		for (int i = 1; i <= n; i ++) {
			for (int j = 1; j <= n; j ++) printf("%I64d ", a[i][j]);
			puts("");
		}
    }
} A;

mat powmod(mat a, ll b) {
    mat res = mat(a.n, 1);
    for ( ; b; b >>= 1) {
        if (a.ok()) return a;
		if (b & 1) {
            res = res * a;
            if (res.ok()) return res;
		}
        a = a * a;
    }
    return res;
}

bool check(ll x) {
    mat B = A;
    B = powmod(B, x);

    if (B.ok()) return 1;
    ll res = 0;
    f1(i, 1, n) {
        if (B.a[n][i] == 0) continue;
        if (a[i] > K / B.a[n][i]) return 1;
		res += B.a[n][i] * a[i];
        if (res >= K) return 1;
    }
    return 0;
}

int main() {
    scanf("%d %I64d", &n, &K);
    f1(i, 1, n) scanf("%I64d", &a[i]);
    reverse(a + 1, a + n + 1);
    while (!a[n]) n --;
    reverse(a + 1, a + n + 1);
    if (n >= 10) {
        f1(i, 1, n) if (a[i] >= K) {puts("0"); return 0;}
        f1(ans, 1, inf) {
            ll prv = 0;
            f1(i, 1, n) {
				a[i] = prv = prv + a[i];
				if (a[i] >= K) {
                    printf("%d\n", ans);
                    return 0;
				}
            }
        }
    }
    else {
		A.init(n);
		f1(i, 1, n) f1(j, 1, i) A.a[i][j] = 1;
        ll st = -1, en = K;
        while (en - st > 1) {
            ll mid = en + st >> 1;
            if (check(mid)) en = mid;
            else st = mid;
        }
        printf("%I64d\n", en);
    }
	return 0;
}