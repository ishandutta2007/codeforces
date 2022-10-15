#include <bits/stdc++.h>
using namespace std;

int T, x, n, m;

bool check() {
    for (int i = 0; i <= n; i++) {
        if (x - m * 10 <= 0) { return true; }
        x = x / 2 + 10;
    }
    return false;
}

int main() {
    for (cin >> T; T; T--) {
        cin >> x >> n >> m;
        cout << (check() ? "YES\n" : "NO\n");
    }
    return 0;
}