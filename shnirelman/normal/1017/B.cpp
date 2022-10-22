#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int N = 200000 + 13;
const int M = 1e9 + 7;
const int B = 600;

/*
*/

void solve() {
    int n;
    cin >> n;

    string a, b;
    cin >> a >> b;

    li c0 = 0, c1 = 0, x0 = 0, x1 = 0;
    li ans = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] == '0') {
            c0++;
            if(b[i] == '0')
                x1++;
        } else {
            c1++;
            if(b[i] == '0')
                x0++;
        }
    }
//    cout << c0 << ' ' << c1 << ' ' << x0 << ' ' << x1 << endl;
//    cout << ans << endl;
    cout << x0 * c0 + x1 * c1 - x0 * x1 << endl;
}

signed main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int t = 1;
//    cin >> t;

    while(t--)
        solve();
}