#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            a[i]--;
        }
        vector<int> b(n);
        for (int i = 0; i < n; i++) {
            cin >> b[i];
            b[i]--;
        }
        vector<int> c(m);
        for (int i = 0; i < m; i++) {
            cin >> c[i];
            c[i]--;
        }
        vector<int> need(n, 0);
        for (int i = 0; i < n; i++) {
            if (a[i] != b[i]) 
                need[b[i]]++;
        }
        for (int i = 0; i < m - 1; i++) 
            need[c[i]]--;
        int last = -1;
        for (int i = 0; i < n; i++) {
            if (b[i] == c[m - 1]) 
                last = i;
        }
        for (int i = 0; i < n; i++) {
            if (b[i] == c[m - 1] && a[i] != b[i] && need[b[i]] > 0) 
                last = i;
        }
        if (last == -1) {
            cout << "NO\n";
        } else {
            a[last] = b[last];
            vector<vector<int>> s(n);
            for (int i = 0; i < n; i++) {
                if (a[i] != b[i]) 
                    s[b[i]].push_back(i);
            }
            vector<int> x;
            for (int i = 0; i < m; i++) {
                if (i == m - 1) {
                    x.push_back(last);
                    break;
                }
                if (!s[c[i]].empty()) {
                    x.push_back(s[c[i]].back());
                    s[c[i]].pop_back();
                } else {
                    x.push_back(last);
                }
            }
            bool ok = true;
            for (int i = 0; i < n; i++) 
                ok &= s[i].empty();
            if (ok) {
                cout << "YES\n";
                for (int i = 0; i < m; i++)
                    cout << x[i] + 1 << " ";
                cout << "\n";
            } else {
                cout << "NO\n";
            }
        }
    }
    return 0;
}