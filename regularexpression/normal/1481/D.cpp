#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[i][j] == a[j][i]) {
                cout << "YES\n";
                for (int k = 0; k < m + 1; k++) 
                    cout << ((k & 1) ? j + 1 : i + 1) << " ";
                cout << "\n";
                return;
            }
        }
    }
    if (m & 1) {
        cout << "YES\n";
        for (int i = 0; i < m + 1; i++) 
            cout << ((i & 1) ? 1 : 2) << " ";
        cout << "\n";
        return;
    }
    if (n == 2) {
        cout << "NO\n";
        return;
    }
    m /= 2;
    vector<int> p(3);
    iota(p.begin(), p.end(), 0);
    do {
        if (a[p[0]][p[1]] == a[p[1]][p[2]]) {
            vector<int> ans;
            if (m & 1) {
                ans.push_back(p[0]);
                for (int i = 0; i < m; i++)
                    ans.push_back(p[i & 1 ^ 1]);
                ans.push_back(p[2]);
                for (int i = 0; i < m - 1; i++)
                    ans.push_back(p[(i & 1) + 1]);
            } else {
                ans.push_back(p[1]);
                for (int i = 0; i < m; i++)
                    ans.push_back(p[i & 1]);
                ans.push_back(p[2]);
                for (int i = 0; i < m - 1; i++)
                    ans.push_back(p[(i & 1) + 1]);
            }
            cout << "YES\n";
            for (int v : ans) 
                cout << v + 1 << " ";
            cout << "\n";
            return;
        }
    } while (next_permutation(p.begin(), p.end()));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) 
        solve();
    return 0;
}