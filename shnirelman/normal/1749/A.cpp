#include<bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int K = 8;
const int N = K * K;
const int LOGN = 35;
const int MOD = 998244353;
const int INF = 1e9 + 13;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<pii> a(m);
    for(int i = 0; i < m; i++) {
        cin >> a[i].f >> a[i].s;
    }

    cout << (m == n ? "NO" : "YES") << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}