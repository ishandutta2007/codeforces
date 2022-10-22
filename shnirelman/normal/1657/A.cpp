#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const li INF64 = 1e18 + 13;
//const int M = 1e9 + 7;
const int M = 998244353;
const int N = 2e5 + 13;
const int LOGN = 30;

/*

*/

void solve() {
    int x, y;
    cin >> x >> y;

    int res = x * x + y * y;

    int sq = int(sqrt(res) + 0.1);

    if(x == 0 && y == 0)
        cout << 0 << endl;
    else if(sq * sq == res)
        cout << 1 << endl;
    else
        cout << 2 << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}