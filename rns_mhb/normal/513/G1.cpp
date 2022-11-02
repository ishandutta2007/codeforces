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



typedef long long ll;

int T, n, k;

int a[N];

ll tot;



void dfs(int x) {

    if (x == k) {

        for (int i = 1; i <= n; i ++) for (int j = i + 1; j <= n; j ++) if (a[i] > a[j]) tot ++;

        return;

    }

    int b[N];

    memcpy(b, a, sizeof b);

    for (int i = 1; i <= n; i ++)

    for (int j = i; j <= n; j ++) {

        memcpy(a, b, sizeof a);

        reverse(a + i, a + j + 1);

        dfs(x + 1);

    }

    memcpy(a, b, sizeof a);

}



int main() {

    scanf("%d %d", &n, &k);

    for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);

    dfs(0);

    ll tmp = 1;

    for (int i = 1; i <= k; i ++) tmp *= n * (n + 1) / 2;

    ld ans = tot;

    ans /= tmp;

    printf("%.12lf\n", (double)ans);

    return 0;

}