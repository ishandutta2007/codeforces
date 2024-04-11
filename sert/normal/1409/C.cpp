#include <bits/stdc++.h>
using namespace std;
bool D = false;
const int INF = (int)1e9 + 41;
typedef long long ll;

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    int dif = y - x;
    for (int len = 1; len <= 100; len++) {
        if (dif % len) continue;
        if (dif / len + 1 > n) continue;

        int st = y - len * (n - 1);
        while (st <= 0) st += len;

        for (int i = 0; i < n; i++)
            cout << st + i * len << " ";
        cout << "\n";

        return;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
#ifdef SERT
    freopen("a.in", "r", stdin);
    D = true;
    t = 4;
#else

#endif
    cin >> t;
    while (t--) {
        solve();
    }
}