#include <bits/stdc++.h>

#define double long double
#define int long long
#define all(x) x.begin(), x.end()
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int h1, h2, a, b;
    cin >> h1 >> h2 >> a >> b;
    for (int x = 0; x < 200000; x++) {
        for (int _ = 0; _ < 12 - 4*(x==0); _++) {
            h1 += a;
            if (h1 >= h2) {
                cout << x << '\n';
                exit(0);
            }
        }
        for (int _ = 0; _ < 12; _++) {
            h1 -= b;
        }
    }
    cout << "-1\n";
}