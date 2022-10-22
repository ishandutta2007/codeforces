#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const li INF64 = 2e18 + 13;
const int N = 2e5 + 113;
const int K = 1e5 + 113;
const int M = 1e9 + 7;
const int A = 26;

/*

*/

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    int ans = INF;
    for(int x = 0; x < 6; x++) {
        for(int y = 0; y < 6; y++) {
            int z = 0;
            bool is = true;
            for(int i = 0; i < n; i++) {
//                bool fl = false;
                int z1 = INF;
                for(int y1 = 0; y1 <= y; y1++) {
//                    int fir = (a[i] - y1) % 3;

                    for(int x1 = 0; x1 <= x && y1 * 2 + x1 <= a[i]; x1++) {

                        if((a[i] - x1 - y1 * 2) % 3 == 0) {
                            z1 = min(z1, (a[i] - x1 - y1 * 2) / 3);
//                            cout << x << ' ' << y << ' ' << i << ' ' << z1 << ' ' << x1 << ' ' << y1 << endl;
//                            fl = true;
                        }

                    }
                }

                is &= (z1 < INF);
                z = max(z, z1);
            }

//            cout << x << ' ' << y << ' ' << z << ' ' << is << endl;

            if(is)
                ans = min(ans, x + y + z);
        }
    }

    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}