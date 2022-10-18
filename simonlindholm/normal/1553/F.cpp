#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 300010
#define sq1 276
#define sq2 521
#define sq3 1091

struct sqdc {
    ll fn[301010] = {}, fns[577] = {};

    void upd_p(int p, ll x) {
        fn[p] += x; fns[p / sq2] += x;
    }

    ll rs_p(int p) {
        return (fn[p] + fns[p / sq2]);
    }

    void upd_r(int l, int r, ll x) {
		int i, lq, rq;
        if (l > r) return;
        lq = (l + sq2 - 1) / sq2; rq = (r - sq2) / sq2;
        for (i = lq; i <= rq; i++) fns[i] += x;
        if (lq > rq) {
            for (i = l; i <= r; i++) fn[i] += x;
        } else {
            for (i = l; i <= sq2 * lq - 1; i++) fn[i] += x;
            for (i = sq2 * (rq + 1); i <= r; i++) fn[i] += x;
        }
    }

    ll rs_r(int l, int r) {
        ll rs = 0;
		int i, lq, rq;
        if (l > r) return 0;
        lq = (l + sq2 - 1) / sq2; rq = (r - sq2) / sq2;
        for (i = lq; i <= rq; i++) rs += fns[i];
        if (lq > rq) {
            for (i = l; i <= r; i++) rs += fn[i];
        } else {
            for (i = l; i <= sq2 * lq - 1; i++) rs += fn[i];
            for (i = sq2 * (rq + 1); i <= r; i++) rs += fn[i];
        }
        return rs;
    }
};

ll n;
int a[200010];
set<int> sm;
sqdc sql, sqr;
long double cl;

void naive() {
    ll i, j, rs = 0;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= i - 1; j++) {
            rs += (a[i] % a[j]); rs += (a[j] % a[i]);
        }
        cout << rs << ' ';
    }
    cout << nl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	ll res;
	int i, j, l, r;
	ll ps[200010], rss[200010];

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    // cl = -clock();

    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> a[i]; ps[i] = ps[i - 1] + a[i];
    }

	res = 0;
    for (i = 1; i <= n; i++) {
        res += ((i - 1) * (ll)a[i]) + ps[i - 1];
        // cout << "res1 = " << res << nl;
        if (a[i] <= sq3) {
            for (j = 1; j <= i - 1; j++) {
                res -= (a[j] * (ll)(a[i] / a[j]) + a[i] * (ll)(a[j] / a[i]));
            }
            sm.insert(a[i]);
        } else {
            res -= (a[i] * sql.rs_r(1, a[i]));
            // cout << "sql = " << a[i] * sql.rs_r(1, a[i]) << nl;
            for (j = 1; j <= sq1; j++) {
                l = (a[i] / (j + 1)) + 1; r = a[i] / j;
                if (l > r) continue;
                res -= (j * (sqr.rs_p(r) - sqr.rs_p(l - 1)));
                /* if (sqr.rs_p(r) - sqr.rs_p(l - 1) != 0) {
                    cout << "sqr = " << j _ l _ r _ sqr.rs_p(r) - sqr.rs_p(l - 1) << nl;
                } */
            }
            for (auto u : sm) {
                // u / a[i] (?)
                if (a[i] / u <= sq1) break;
                res -= (u * (ll)(a[i] / u));
            }
        }

        for (j = 1; j <= sq1; j++) {
            l = (a[i] / (j + 1)) + 1; r = a[i] / j;
            if (l > r) continue;
            sql.upd_p(l, j); sql.upd_p(r + 1, -j);
        }
        sqr.upd_r(a[i], maxn - 1, a[i]);

        // cout << "res2 = " << res << nl;
        rss[i] = res;
    }

    for (i = 1; i <= n; i++) cout << rss[i] << ' ';
    cout << nl;

    // naive();

    /* cl += clock();
    cl /= CLOCKS_PER_SEC;
    cout << fixed << setprecision(20);
    cout << cl << nl; */

    return 0;
}