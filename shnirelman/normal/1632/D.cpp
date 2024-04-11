#include <bits/stdc++.h>

#define f first
#define s second
//#define x first
//#define y second
//#define int li
#define err if(debug_out)cout

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
using pld = pair<ld, ld>;

const int INF = 1e9 + 13;
const li INF64 = 1e18 + 13;
const int N = 3e5 + 13;
const int LOGN = 20;
const int K = 22;
const int M = 998244353;//1e9 + 7;
const int A = 26;
const ld eps = 1e-8;

mt19937 rnd(45768);

/*
*/

int a[N], lf[N], dp[N];
int st[LOGN][N];
int max2[N];

int get(int l, int r) {
    int k = max2[r - l];

    return __gcd(st[k][l], st[k][r - (1 << k)]);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

     int n;
     cin >> n;

     for(int i = 0; i < n; i++)
        cin >> a[i];

    max2[1] = 0;
    for(int i = 2; i <= n; i++) {
        max2[i] = max2[i / 2] + 1;
    }

    for(int i = 0; i < n; i++) {
        st[0][i] = a[i];
    }

    for(int i = 1; i <= LOGN; i++) {
        for(int j = 0; j + (1 << i) <= n; j++) {
            st[i][j] = __gcd(st[i - 1][j], st[i - 1][j + (1 << i - 1)]);
        }
    }

    for(int i = 0; i < n; i++) {
        lf[i] = (i == 0 ? -1 : lf[i - 1]);

        int l = -1, r = i + 1;
        while(r - l > 1) {
            int m = (l + r) / 2;

            if(get(m, i + 1) < i + 1 - m)
                l = m;
            else
                r = m;
        }

        if(get(r, i + 1) == i + 1 - r) {
            lf[i] = max(lf[i], r);
        }
    }

    for(int i = 0; i < n; i++) {
        dp[i] = (lf[i] == -1 ? 0 : 1 + (lf[i] > 0 ? dp[lf[i] - 1] : 0));
        cout << dp[i] << ' ';
    }
    cout << endl;
}