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
const int N = 1e6 + 113;
const int K = 1e5 + 113;
const int M = 1e9 + 7;
const int A = 26;

/*

*/

mt19937 rnd(3666);

void solve() {
    int x, y;
    cin >> x >> y;

    int s = x + y;

    if(s % 2 != 0) {
        cout << -1 << ' ' << -1 << endl;
        return;
    }

    for(int i = 0; i <= 100; i++) {
        for(int j = 0; j <= 100; j++) {
            if(i + j == s / 2 && abs(x - i) + abs(y - j) == s / 2) {
                cout << i << ' ' << j << endl;
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