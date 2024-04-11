//made by Sert
#include <bits/stdc++.h>
using namespace std;
const int INF = (int)1e9 + 34;
const int N = (int)1e6 + 34;

bool isSS(string &sb, string &s) {
    return s.find(sb) != string::npos;
}

void solve() {
    int n;
    cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int it = 0; it < n; it++) {
        int ind = -1;
        for (int i = it; i < n; i++) {
            bool ok = true;
            for (int j = it; j < n; j++) {
                if (!isSS(a[i], a[j])) ok = false;
            }
            if (ok) ind = i;
        }
        if (ind == -1) {
            cout << "NO\n";
            return;
        }
        swap(a[ind], a[it]);
    }
    cout << "YES\n";
    for (int i = 0; i < n; i++) {
        cout << a[i] << "\n";
    }
}

int main() {
#ifdef SERT
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    solve();
    solve();
    //solve();
    //solve();
#endif
    solve();
    return 0;
}