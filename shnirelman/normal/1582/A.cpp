#include <bits/stdc++.h>

#define f first
#define s second
#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const li INF = 1e18 + 13;
const int N = 2e7 + 13;
//const int M = 1e5 + 13;
const int A = 26;

void solve() {
    li a, b, c;
    cin >> a >> b >> c;

    li s = (a + b * 2 + c * 3);

    li ans = 3;

    if(s < 10) {
        for(int i = 0; i <= a; i++) {
            for(int j = 0; j <= b; j++) {
                for(int k = 0; k <= c; k++) {
//                    cout << i << ' ' << j << ' ' << k << ' ' << abs(s - (i + j * 2 + k * 3) * 2) << endl;
                    ans = min(ans, abs(s - (i + j * 2 + k * 3) * 2));
                }
            }
        }

        cout << ans << endl;
        return;
    }

    if(s % 2 == 0)
        cout << 0 << endl;
    else
        cout << 1 << endl;
}

signed main() {
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
        solve();
}