#include <bits/stdc++.h>

#define pb push_back
#define int long long
#define ld long double
using namespace std;
const int M = 998244353;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        string s;
        cin >> s;
        s = '-' + s;
        vector<int> P(n + 1);
        for (int i = 1; i <= n; i++) {
            P[i] = P[i - 1];
            if (s[i] == '+') {
                P[i]++;
            } else {
                P[i]--;
            }
        }
        vector<int> prefmin(n + 1), prefmax(n + 1);
        for (int i = 1; i <= n; i++) {
            prefmin[i] = min(prefmin[i - 1], P[i]);
            prefmax[i] = max(prefmax[i - 1], P[i]);
        }
        vector<int> sufmin(n + 2), sufmax(n + 2);
        sufmin[n + 1] = P[n];
        sufmax[n + 1] = P[n];
        for (int i = n; i >= 0; i--) {
            sufmin[i] = min(sufmin[i + 1], P[i]);
            sufmax[i] = max(sufmax[i + 1], P[i]);
        }
        while (m--) {
            int l, r;
            cin >> l >> r;
            int minn = min(prefmin[l - 1], P[l - 1] + sufmin[r + 1] - P[r]);
            int maxx = max(prefmax[l - 1], P[l - 1] + sufmax[r + 1] - P[r]);
            cout << maxx-minn+1 << '\n';
        }
    }
}