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
const int N = 3e5 + 13;
const int LOGN = 20;
const int K = 11;
const int M = 1e9 + 7;
const int A = 26;

/*
4
1 2 3 4
1
1 5
*/

void solve() {
    int n, m;
    cin >> n >> m;

    int a = (n - m) / (m + 1);
    int b = a + 1;

    int y = (n - m) % (m + 1);
    int x = m + 1 - y;

    cout << n * 1ll * (n + 1) / 2 - a * 1ll * (a + 1) / 2 * x - b * 1ll * (b + 1) / 2 * y << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}