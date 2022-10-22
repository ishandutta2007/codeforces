#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int N = 2e5 + 13;
const int M = 1e9 + 7;
const int A = 26;

void solve() {
    int n, m;
    cin >> n >> m;

    if(n == 1 || m == 1) {
        cout << (n == 1 && m == 1 ? 0 : 1) << endl;
    } else {
        cout << 2 << endl;
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
        solve();
}