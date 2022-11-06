#include<bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
#define eb emplace_back
#define mp make_pair

#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()

typedef long long ll;
typedef long double ld;

const int oo = 1e9 + 7;

void upd(int &x, int y) {
    x = max(x, y);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int lo = 0, hi = oo;
    while (hi - lo > 1) {
        int mi = (lo + hi) / 2;
        vector<int> dp(2, 0);
        dp[1] = -oo;
        for (int i = 0; i < n; i++) {
            auto dp2 = dp;
            if (a[i] <= mi) upd(dp2[0], dp[1] + 1);
            upd(dp2[1], dp[0] + 1);
            dp = dp2;
        }
        int mx = max(dp[0], dp[1]);
        dp[0] = 0;
        dp[1] = -oo;
        for (int i = 0; i < n; i++) {
            auto dp2 = dp;
            if (a[i] <= mi) upd(dp2[1], dp[0] + 1);
            upd(dp2[0], dp[1] + 1);
            dp = dp2;
        }
        mx = max({mx, dp[0], dp[1]});
        if (mx >= k) hi = mi; else lo = mi;
    }
    cout << hi;
    return 0;
}