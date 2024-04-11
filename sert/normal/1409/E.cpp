#include <bits/stdc++.h>
using namespace std;
bool D = false;
const int INF = (int)1e9 + 41;

void solve() {
    int n, t, qq;
    cin >> n >> t;
    vector<int> x(n);
    for (int &xx : x) cin >> xx;
    for (int i = 0; i < n; i++) cin >> qq;
    sort(x.begin(), x.end());

    if (x.back() - x[0] <= t * 2 + 1) {
        cout << n << "\n";
        return;
    }

    vector<int> fn, tot;
    int lst = 0;
    int mxPref = 0;
    int cur = 0;
    int ans = 0;

    for (int i = 0; i < n; i++) {
        cur = max(cur, i + 1);
        while (cur < n && x[cur] - x[i] <= t) cur++;
        fn.push_back(cur);
        tot.push_back(cur - i);

        while (lst < i && fn[lst] <= i) {
            mxPref = max(mxPref, tot[lst]);
            lst++;
        }

        ans = max(ans, tot[i] + mxPref);
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
#ifdef SERT
    freopen("a.in", "r", stdin);
    D = true;
    t = 4;
#else

#endif
    cin >> t;
    while (t--) {
        solve();
    }
}