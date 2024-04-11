#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

typedef long long ll;
const int N = 1e6 + 7;

int n, m, x[N], h[N], ans, dx, dh;

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> x[i] >> h[i];
    }

    for (int i = 1; i < m; i++) {
        dh = abs(h[i] - h[i - 1]);
        dx = abs(x[i] - x[i - 1]);
        if (dh > dx) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
        ans = max(ans, max(h[i], h[i - 1]) + (dx - dh) / 2);
    }

    ans = max(ans, x[0] + h[0] - 1);
    ans = max(ans, n - x[m - 1] + h[m - 1]);

    cout << ans;


    return 0;
}