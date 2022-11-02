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



#define N 40330



int n, m;

int a[N], b[N];

int f;



int main() {

    scanf("%d %d", &n, &m);

    f = 1; for (int i = 1; i <= n; i ++) f *= i;

    for (int i = 1; i <= n; i ++) a[i] = i;

    int cnt = 0;

    while (1) {

        int tmp = 0;

        for (int i = 1; i <= n; i ++)

        for (int j = i; j <= n; j ++) {

            int mn = inf;

            for (int k = i; k <= j; k ++) chkmin(mn, a[k]);

            tmp += mn;

        }

        b[cnt++] = tmp;

        next_permutation(a + 1, a + n + 1);

        if (cnt == f) break;

    }

    int mx = 0;

    for (int i = 0; i < cnt; i ++) chkmax(mx, b[i]);

    int ncnt = 0;

    for (int i = 0, j = 0; i < f; i ++) {

        if (b[i] == mx) {

            j ++;

            if (j == m) {

                for (int i = 1; i <= n; i ++) printf("%d ", a[i]);

            }

        }

        next_permutation(a + 1, a + n + 1);

    }

    return 0;

}