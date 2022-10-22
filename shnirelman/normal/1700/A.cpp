#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const li INF64 = 1e18 + 13;
const int M = 1e9 + 7;
const int N = 1e5 + 13;
const int LOGN = 30;

void solve() {
    int n, m;
    cin >> n >> m;

    li ans = 0;
    for(int i = 0; i < m; i++)
        ans += i + 1;
    for(int i = 1; i < n; i++)
        ans += i * m + m;
    cout << ans << endl;

//    cout << m * (m + 1) / 2 + n * (m - 1) + m * 1ll * n * (n - 1) / 2 << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}