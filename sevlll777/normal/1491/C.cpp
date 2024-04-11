#include <bits/stdc++.h>

#define pb push_back
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ld long double
using namespace std;
const int M = 1000000007;

void solve() {
    int n;
    cin >> n;
    vector<int> S(n);
    for (int i = 0; i < n; i++) cin >> S[i];
    vector<int> nxt(n + 1);
    for (int i = 0; i <= n; i++) nxt[i] = i;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (i + S[i] >= n) {
            int r = S[i] - (n - i) + 1;
            r = min(r, S[i] - 1);
            ans += r;
            S[i] -= r;
        }
        while (S[i] > 1) {
            ans++;
            int j = i;
            while (j < n) {
                j = nxt[j];
                if (j >= n) {
                    break;
                }
                S[j]--;
                if (S[j] == 0) {
                    S[j] = 1;
                    nxt[j] = nxt[j + 1];
                    for (int ii = 0; ii < n; ii++) {
                        if (nxt[ii] == j) {
                            nxt[ii] = nxt[j + 1];
                        }
                    }
                    j++;
                } else {
                    j += S[j] + 1;
                }
            }
        }
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

}