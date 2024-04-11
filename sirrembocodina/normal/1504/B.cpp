#include <bits/stdc++.h>

#define int int64_t

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string a, b;
        cin >> a >> b;
        int bal = 0;
        vector<int> p;
        p.push_back(0);
        for (int i = 0; i < n; i++) {
            if (a[i] == '0') {
                bal++;
            } else {
                bal--;
            }
            if (bal == 0) {
                p.push_back(i + 1);
            }
        }
        bool ok = true;
        for (int i = p.back(); i < n; i++) {
            if (a[i] != b[i]) {
                ok = false;
            }
        }
        for (int i = 0; i + 1 < p.size(); i++) {
            for (int j = p[i]; j < p[i + 1]; j++) {
                if ((a[j] == b[j]) != (a[p[i]] == b[p[i]])) {
                    ok = false;
                }
            }
        }
        if (ok) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}