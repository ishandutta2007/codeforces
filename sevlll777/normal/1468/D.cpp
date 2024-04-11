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
        int n, m, a, b;
        cin >> n >> m >> a >> b;
        int aa = a, bb = b;
        vector<int> S(m);
        for (int i = 0; i < m; i++) cin >> S[i];
        sort(S.begin(), S.end());
        int l = 0, r = m + 1;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            a = aa;
            b = bb;
            int f = mid - 1;
            int TIME = 0;
            int kek = 0;
            while (true) {
                if (abs(a - b) >= 2 && f >= 0) {
                    kek = max(kek, TIME + S[f]);
                    f--;
                    if (a < b) {
                        b--;
                    } else {
                        b++;
                    }
                    TIME++;
                } else {
                    if (a < b) {
                        TIME += a - 1;
                    } else {
                        TIME += n - a;
                    }
                    TIME += abs(b-a)-1;
                    break;
                }
            }
            if (kek <= TIME && f < 0) {
                l = mid;
            } else {
                r = mid;
            }
        }
        cout << l << '\n';
    }

}