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
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> A(n);
        for (int i = 0; i < n; i++) cin >> A[i];
        vector<int> cnt(n + 1);
        int f = 0;
        for (auto x : A) cnt[x]++;
        for (int x = 1; x <= n; x++) {
            if (cnt[x] == 1) {
                for (int i = 0; i < n; i++) {
                    if (A[i] == x) {
                        f = 1;
                        cout << i+1 << '\n';
                        break;
                    }
                }
                break;
            }
        }
        if (f == 0) cout << "-1\n";
    }


}