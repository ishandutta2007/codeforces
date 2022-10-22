#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 2e9 + 13;
const li INF64 = 2e18 + 13;
const int M = 998244353;
const int A = 1e6 + 13;
const int N = 5e5 + 13;
const int B = 400;
const int LOGN = 20;

mt19937 rnd(2);

int m;
int pref[N], suf[N];
int dp[N];

void upd(int i, int x, int y) {
//    if(dp[i] >= x)
//        return;

    dp[i] = max(dp[i], x);
    for(int j = i; j <= m; j |= j + 1)
        pref[j] = max(pref[j], x - y);

    for(int j = m - i; j <= m; j |= j + 1)
        suf[j] = max(suf[j], x + y);
}

int get(int i, int t[N]) {
    int res = -INF;
    for(; i >= 0; i = (i & (i + 1)) - 1)
        res = max(res, t[i]);
    return res;
}

int a[N];
li p[N];

/*
4
1
1
1
-1
2
1 1
2
2 -1

1
2
2 -1
*/

void solve() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for(int i = 0; i <= n + 10; i++) {
        dp[i] = suf[i] = pref[i] = -INF;
        p[i] = 0;
    }


    vector<li> b(n + 1, 0);
    for(int i = 0; i < n; i++) {
        p[i + 1] = p[i] + a[i];
        b[i + 1] = p[i + 1];
    }

//    for(int i = 0; i <= n; i++) {
//        cout << p[i] << ' ';
//    }
//    cout << endl;

    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());

    for(int i = 0; i <= n; i++) {
        p[i] = lower_bound(b.begin(), b.end(), p[i]) - b.begin();
    }

//    for(int i = 0; i <= n; i++) {
//        cout << p[i] << ' ';
//    }
//    cout << endl;

//    dp[0] = 0;
//    for(int i = 1, j = 0; i <= n; i++) {
//        while(j > 0 && p[j - 1] < p)
//    }

    m = b.size();
    for(int i = 0; i <= m + 10; i++) {
        dp[i] = suf[i] = pref[i] = -INF;
    }

    upd(p[0], 0, 0);
    for(int i = 1; i <= n; i++) {
        int res = max({dp[p[i]], get(p[i] - 1, pref) + i, get(m - p[i] - 1, suf) - i});

        upd(p[i], res, i);

//        cout << i << ' ' << res << endl;

        if(i == n) {
            cout << res << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}