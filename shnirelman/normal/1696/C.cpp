#include <bits/stdc++.h>

#define f first
#define s second
#define int li

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

void solve() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, li>> a;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;

        pair<int, li> b(x, 1ll);
        while(b.f % m == 0) {
            b.f /= m;
            b.s *= m;
        }

        if(a.empty() || a.back().f != b.f)
            a.push_back(b);
        else
            a.back().s += b.s;
    }

    int k;
    cin >> k;

    vector<pair<int, li>> b;
    for(int i = 0; i < k; i++) {
        int x;
        cin >> x;

        pair<int, li> c(x, 1ll);
        while(c.f % m == 0) {
            c.f /= m;
            c.s *= m;
        }

        if(b.empty() || b.back().f != c.f)
            b.push_back(c);
        else
            b.back().s += c.s;
    }

    cout << (a == b ? "YES" : "NO") << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}