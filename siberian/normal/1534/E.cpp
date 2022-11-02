#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define all(a) (a).begin(), (a).end()
#define mp make_pair

template<typename T1, typename T2> 
inline void chkmin(T1& x, const T2& y) {
    if (y < x) x = y;
}

template<typename T1, typename T2>
inline void chkmax(T1& x, const T2& y) {
    if (x < y) x = y;
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    
    int n, k;
    cin >> n >> k;
    vector<bool> dp(n + 1, false);
    vector<pair<int, int>> par(n + 1);

    dp[0] = 1;
    queue<int> q;
    q.push(0);

    while (!q.empty()) {
        int now = q.front();
        q.pop();
        int haveZero = n - now;
        for (int one = 0; one <= min(now, k); ++one) {
            int zero = k - one;
            if (haveZero < zero) continue;
            int nxt = now - one + zero;
            if (nxt < 0 || nxt > n) continue;
            if (dp[nxt]) continue;
            // cerr << "now = " << now << " nxt = " << nxt << " one = " << one << endl;
            dp[nxt] = true;
            par[nxt] = {now, one};
            q.push(nxt);
        }
    }

    if (!dp[n]) {
        cout << "-1\n";
        exit(0);
    }

    vector<bool> used(n, true);

    int have = n;
    int ans = 0;

    // cout << "par = " << endl;
    // for (auto i : par) {
    //     cout << i.first << " " << i.second << endl;
    // }

    while (have) {
        int one = par[have].second;
        int zero = k - one;
        swap(one, zero);
        cout << "?";
        for (int i = 0; i < n; ++i) {
            if (one > 0 && used[i]) {
                cout << " " << i + 1;
                --one;
                used[i] = false;
            } else if (zero > 0 && !used[i]) {
                cout << " " << i + 1;
                --zero;
                used[i] = true;
            }
        }
        // assert(one == 0 && zero == 0);
        cout << endl;
        int fans;
        cin >> fans;
        ans ^= fans;
        have = par[have].first;
    }

    cout << "! " << ans << endl;

    return 0;
}