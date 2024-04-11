#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cstdlib>
#include <ctime>

#define ff first
#define ss second

using namespace std;

typedef long long ll;
const ll N = 1e6 + 7;

ll n, m, x[N], l[N], uk;
pair <pair<ll, ll>, ll> a[N];
pair <ll, ll> s[N];
ll p[N], sz, r, L, R, M, len, ind, X;
ll ans[N];

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    scanf("%I64d", &n);
    for (int i = 0; i < n; i++)
        scanf("%I64d%I64d", &x[i], &l[i]);
    x[n] = x[n - 1] + l[n - 1];
    l[n] = 34;
    scanf("%I64d", &m);
    for (int i = 0; i < m; a[i].ss = i++) {
        scanf("%I64d%I64d", &a[i].ff.first, &a[i].ff.second);
        a[i].ff.ff--;
        a[i].ff.ss--;
    }

    sort(a, a + m);
    uk = m - 1;

    for (int i = n - 1; i >= 0; i--) {
        r = x[i] + l[i];
        if (r < x[i + 1]) {
            p[sz + 1] = p[sz] + x[i + 1] - r;
            s[sz++] = make_pair(r, x[i + 1]);
        } else {
            if (sz)
                while (s[sz - 1].second <= r) {
                    sz--;
                    if (sz == 0) break;
                }
            if (sz) {
                s[sz - 1].first = max(r, s[sz - 1].first);
                p[sz] = p[sz - 1] + s[sz - 1].second - s[sz - 1].first;
            }
        }

        while (true) {
            if (uk < 0) break;
            if (a[uk].ff.ff != i) break;
            if (sz == 0) {
                ///break;
                uk--;
                continue;
            }
            R = sz;
            L = 0;
            X = x[a[uk].ff.ss];
            while (R - L > 1) {
                M = (L + R) / 2;
                if (s[M].second >= X)
                    L = M;
                else
                    R = M;
            }
            ind = a[uk].ss;
            //cerr << ind << " " << uk << " ind\n";
            ans[ind] = p[sz];
            ans[ind] -= p[L + 1];
            len = min(X, s[L].second) - s[L].first;
            ans[ind] += max(len, 0ll);
            uk--;
        }
    }

    for (int i = 0; i < m; i++)
        printf("%I64d\n", ans[i]);

    return 0;
}