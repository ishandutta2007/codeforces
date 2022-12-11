#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#ifdef SERT
bool D = true;
#else
bool D = false;
#endif

void solve() {
    int n, m;
    cin >> n >> m;
    vector<bool> u(n, false);
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        u[b - 1] = true;
    }
    int pos = -1;
    for (int i = 0; i < n; i++)
        if (!u[i])
            pos = i;
    for (int i = 0; i < n; i++) {
        if (i != pos) {
            cout << i + 1 << " " << pos + 1 << "\n";
        }
    }
}

int main() {
    int t;
    if (D) {
        freopen("../a.in", "r", stdin);
    }
    cin >> t;
    while (t--) {
        solve();
    }
}