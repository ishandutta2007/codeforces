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
const int M = 998244353;
const int B = 600;

/*
*/

void solve() {
    li a, b;
    cin >> a >> b;

    if(a == b) {
        cout << "0 0" << '\n';
        return;
    }

    li d = abs(a - b);

    li a1 = a / d * d;
    li a2 = (a + d - 1) / d * d;

    cout << d << ' ' << min(a - a1, a2 - a) << '\n';
}


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();


}