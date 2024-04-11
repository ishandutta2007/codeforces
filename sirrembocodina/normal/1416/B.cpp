#include "bits/stdc++.h"

#define int long long
#define forn(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        int sum = 0;
        forn (i, n) {
            cin >> a[i];
            sum += a[i];
        }
        if (sum % n) {
            cout << -1 << endl;
            continue;
        }
        vector<int> ansi, ansj, ansk;
        for (int i = 1; i < n; i++) {
            ansi.push_back(0);
            ansj.push_back(i);
            int x = (a[i] + i) / (i + 1) * (i + 1);
            ansk.push_back(x - a[i]);
            a[0] -= x - a[i];
            a[i] = x;
            ansi.push_back(i);
            ansj.push_back(0);
            ansk.push_back(a[i] / (i + 1));
            a[0] += a[i];
            a[i] = 0;
        }
        for (int i = 1; i < n; i++) {
            ansi.push_back(0);
            ansj.push_back(i);
            ansk.push_back(sum / n);
        }
        cout << ansi.size() << endl;
        forn (i, ansi.size()) {
            cout << ansi[i] + 1 << " " << ansj[i] + 1 << " " << ansk[i] << endl;
        }
    }
}