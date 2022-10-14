#include <bits/stdc++.h>

#define pb push_back
#define int long long
#define ld long double
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> W(n);
        for (int i = 0; i < n; i++) cin >> W[i];
        vector<int> deg(n);
        for (int i = 0; i < n - 1; i++) {
            int a, b;
            cin >> a >> b;
            a--;
            b--;
            deg[a]++;
            deg[b]++;
        }
        vector<int> kek;
        for (int v = 0; v < n; v++) {
            for (int _ = 0; _ < deg[v]-1; _++) {
                kek.pb(W[v]);
            }
        }
        sort(kek.rbegin(), kek.rend());
        int sum = 0;
        for (auto x : W) sum += x;
        for (int i = 0; i < n-1; i++) {
            cout << sum << ' ';
            if (i != n-2) {
                sum += kek[i];
            }
        }
        cout << '\n';

    }
}