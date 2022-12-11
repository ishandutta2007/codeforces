#pragma GCC diagnostic ignored "-Wunused-result"
#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
const int M = 17;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    vector<int> lastPos(70, -1);

    vector<vector<int>> t(M, vector<int>(n, 0));    
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
        t[0][i] = sum;
    }
    for (int lv = 1; lv < M; lv++) {
        for (int i = 0; i + (1 << lv) <= n; i++) {
            t[lv][i] = min(t[lv - 1][i], t[lv - 1][i + (1 << (lv - 1))]);
        }
    }

    // for (int lv = 0; lv < 4; lv++) {
    //     for (int i = 0; i < n + 1 - (1 << lv); i++)
    //         cout << t[lv][i] << " ";
    //     cout << "\n";
    // }

    vector<int> minPow(n + 1, 0);
    for (int i = 2; i <= n; i++) minPow[i] = minPow[i / 2] + 1;

    auto getMin = [&](int l, int r) {
        int lv = minPow[r - l];
        return min(t[lv][l], t[lv][r - (1 << lv)]);
    };

    int ans = 0;
    sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
        int mxPos = -1;
        lastPos[a[i] + 34] = i;

        for (int mx = 30; mx >= a[i]; mx--) {
            int pos = lastPos[mx + 34];
            if (pos == -1 || pos < mxPos || i - mxPos == 1) continue;

            int pp = getMin(mxPos + 1, min(i, pos + 1));
            if (mxPos == -1) pp = min(pp, 0);
            // cout << mxPos + 1 << " " << min(i, pos + 1) << "\n";
            // cout << i << " " << a[i] << " " << sum << "-" << mx << "-" << getMin(mxPos + 1, pos + 1) << "\n";

            ans = max(ans, sum - mx - pp);
            mxPos = pos;
        }
    }

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
#ifdef SERT
    int T = 6;
    for (int i = 1; i < T; i++) solve();    
#endif
}