#include <bits/stdc++.h>

#define pb push_back
#define int long long
#define ld long double
using namespace std;
const int M = 1000000007;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int> A;
    vector<int> cnt(400);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        int l = (int) ceil(log2(x + 1));
        A.pb(x);
        cnt[l]++;
    }
    bool ok = false;
    for (auto x : cnt) {
        if (x >= 3) {
            cout << "1\n";
            exit(0);
        }
        if (x == 2) ok = true;
    }
    if (0) {
        cout << "-1\n";
    } else {
        int ans = 1e18;
        for (int l = 0; l < n; l++) {
            for (int r = l; r < n; r++) {
                int num = 0;
                for (int x = l; x <= r; x++) num ^= A[x];
                int huy = 0;
                for (int rr = r+1; rr < n; rr++) {
                    huy ^= A[rr];
                    if (huy < num) {
                        ans = min(ans,r-l+rr-r-1);
                    }
                }
            }
        }
        if (ans == 1e18)ans = -1;
        cout << ans << '\n';
    }
}