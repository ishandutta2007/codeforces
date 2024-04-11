#include "bits/stdc++.h"

using namespace std;

#define int long long
#define forn(i, n) for (int i = 0; i < (int)(n); i++)

int32_t main() {
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    forn (q, t) {
        int n;
        cin >> n;
        vector<int> a(n);
        forn (i, n) {
            cin >> a[i];
        }
        vector<int> ans;
        while (true) {
            vector<bool> b(n + 1);
            forn (i, n) {
                b[a[i]] = true;
            }
            int mx = 0;
            forn (i, n + 1) {
                if (!b[i]) {
                    mx = i;
                    break;
                }
            }
            if (mx != n) {
                ans.push_back(mx);
                a[mx] = mx;
            } else {
                int j = -1;
                forn (i, n) {
                    if (a[i] != i) {
                        j = i;
                        break;
                    }
                }
                if (j == -1) {
                    break;
                }
                ans.push_back(j);
                a[j] = mx;
            }
        }
        cout << ans.size() << endl;
        forn (i, ans.size()) {
            cout << ans[i] + 1 << " ";
        }
        cout << endl;
    }
}