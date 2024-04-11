#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const li INF64 = 1e18 + 13;
const int M = 1e9 + 7;
//const int M = 998244353;
const int N = 100 + 13;
const int LOGN = 30;

/*
*/

void solve() {
//    int n;
//    cin >> n;

    int a, b, c;
    cin >> a >> b >> c;

    li z = c;
    for(li y = z + b; ; y += z) {
        for(li x = y + a, j = 0; j < 20; j++, x += y) {
//            cout << x << ' ' << y << ' ' << z << endl;
            if(x % y == a && y % z == b && z % x == c) {
                cout << x << ' ' << y << ' ' << z << endl;
                return;
            }
        }
    }

}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}