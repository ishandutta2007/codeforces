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

int sum(int a, int b) {
    a += b;
    return (a >= M ? a - M : a);
}

int mul(int a, int b) {
    return a * 1ll * b % M;
}

int dif(int a, int b) {
    return sum(a, M - b);
}

int pow2(int n, int k) {
    if(k == 0)
        return 1;

    int pw = pow2(n, k / 2);
    pw = mul(pw, pw);

    return (k % 2 == 0 ? pw : mul(pw, n));
}

/*
*/

set<int> ans;

void solve(int n, vector<int> a) {
    int mx = 0;
    for(int i = 0; i < n; i++)
        if(a[i] > a[mx])
            mx = i;

    int mx2 = -1;
    int pref = -1;
    for(int i = 0; i < mx; i++) {
        if(a[i] > pref) {
            pref = a[i];
        } else if(a[i] > mx2) {
            mx2 = a[i];
        } else
            return;
    }

    vector<int> suf(n, INF);
    suf[n - 1] = -1;
    for(int i = n - 2; i > mx; i--) {
        int x = a[i];
        if(a[i] > a[i + 1])
            suf[i] = min(suf[i], suf[i + 1]);
        if(a[i] > suf[i + 1])
            suf[i] = min(suf[i], a[i + 1]);
    }

    vector<pii> dp(n, pii(INF, -1));
    dp[mx] = {mx2, -1};

    for(int i = mx + 1; i < n; i++) {
        if(a[i] < a[i - 1]) {
            dp[i].f = min(dp[i].f, dp[i - 1].f);
        }

        if(a[i] < dp[i - 1].s) {
            dp[i].f = min(dp[i].f, a[i - 1]);
        }

        if(a[i] > a[i - 1]) {
            dp[i].s = max(dp[i].s, dp[i - 1].s);
        }

        if(a[i] > dp[i - 1].f) {
            dp[i].s = max(dp[i].s, a[i - 1]);
        }

        if(dp[i].s > suf[i])
            ans.insert(a[i]);
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    solve(n, a);
    reverse(a.begin(), a.end());
    solve(n, a);

    cout << ans.size() << endl;
}