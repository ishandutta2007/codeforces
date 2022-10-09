#include <bits/stdc++.h>
#define int int64_t

using namespace std;


int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<int> m, t1, t2;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'M') {
                m.push_back(i);
            } else if (t1.size() < n / 3) {
                t1.push_back(i);
            } else {
                t2.push_back(i);
            }
        }
        if (m.size() != n / 3 || t1.size() != n / 3 || t2.size() != n / 3) {
            cout << "NO" << endl;
            continue;
        }
        bool ok = true;
        for (int i = 0; i < n / 3; i++) {
            if (!(t1[i] < m[i] && m[i] < t2[i])) {
                ok = false;
            }
        }
        cout << (ok ? "YES" : "NO") << endl;
    }
}