#include <bits/stdc++.h>

#define f first
#define s second
//#define x first
//#define y second
//#define int li
#define err if(debug_out)cout

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
using pld = pair<ld, ld>;

const int INF = 1e9 + 13;
const li INF64 = 1e18 + 13;
const int N = 2e5 + 13;
const int LOGN = 20;
const int K = 22;
const int M = 998244353;//1e9 + 7;
//const int A = 26;
const ld eps = 1e-8;

mt19937 rnd(45768);

/*
*/

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, x, y;
    cin >> a >> x >> y;

    if(y % a == 0) {
        cout << -1 << endl;
    } else {
        int n = y / a;
        if(n == 0 || n % 2 == 1) {
            int l = (a % 2 == 0 ? -a / 2 + 1 : -a / 2);
            int r = -l;

//            cout << n << ' ' << l << ' ' << r << endl;

            if(l <= x && x <= r)
                cout << (n == 0 ? 1 : (n / 2) * 3 + 2) <<  endl;
            else
                cout << -1 << endl;
        } else {
            if(-a < x && x < 0)
                cout << (n - 1) / 2 * 3 + 3 << endl;
            else if(0 < x && x < a)
                cout << (n - 1) / 2 * 3 + 4 << endl;
            else
                cout << -1 << endl;
        }
    }
}