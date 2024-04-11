#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

typedef long long ll;
const int N = 1e6 + 7;

ll a, b, n, st, t, m, l, x;
ll L, R, M, f;
string s;

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    cin >> a >> b >> n;
    for (int i = 0; i < n; i++) {
        cin >> l >> t >> m;
        x = a + (l - 1) * b;
        if (x > t) {
            cout << "-1\n";
            continue;
        }
        L = 1;
        R = 1e8;
        while (R - L > 1) {
            M = (L + R) / 2;
            f = x * M + b * (M * (M - 1)) / 2;
            if (f <= m * t && t >= x + b * (M - 1))
                L = M;
            else
                R = M;
        }
        cout << l + L - 1 << "\n";
    }

    return 0;
}