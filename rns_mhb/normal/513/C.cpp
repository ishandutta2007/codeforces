#include <bits/stdc++.h>

using namespace std;



#define pb push_back

#define x first

#define y second



template <class T> bool chkmin(T &a, T b) { return a > b ? a = b, 1 : 0; }

template <class T> bool chkmax(T &a, T b) { return a < b ? a = b, 1 : 0; }

typedef long long ll;

typedef unsigned long long ull;

typedef long double ld;

typedef pair<int, int> pii;

typedef pair<ll, ll> pll;

const int inf = 1e9;

const ll linf = 1e18;

const int mod = 1e9 + 7;

const double eps = 1e-7;



#define N 10



int n;

int l[N], r[N];



int main() {

    scanf("%d", &n);

    ld all = 1;

    for (int i = 1; i <= n; i ++) {

        scanf("%d %d", &l[i], &r[i]);

        all *= (r[i] - l[i] + 1);

    }

    ld ans = 0;

    for (int i = 1; i <= n; i ++) {

        for (int j = l[i]; j <= r[i]; j ++) {

            ll tot = 0;

            for (int k = 1; k <= n; k ++) {

                if (k == i) continue;

                ll tmp = max(0, r[k] - j + (k < i));

                if (l[k] > j) tmp = r[k] - l[k] + 1;

                for (int t = 1; t <= n; t ++) {

                    if (t == i || t == k) continue;

                    ll tp = max(0, j - l[t] + (t > i));

                    if (r[t] < j) tp = r[t] - l[t] + 1;

                    tmp *= tp;

                }

                tot += tmp;

            }

            ans += 1.0 * j * tot / all;

        }

    }

    printf("%.12lf\n", (double)ans);

    return 0;

}