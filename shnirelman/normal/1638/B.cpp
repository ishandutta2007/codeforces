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
const int N = 3e5 + 13;
const int LOGN = 20;
const int K = 22;
const int M = 998244353;//1e9 + 7;
//const int A = 26;
const ld eps = 1e-8;

mt19937 rnd(45768);

/*
*/

void solve() {
    int n;
    cin >> n;

    vector<int> a(n), c, d;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] % 2 == 0)
            c.push_back(a[i]);
        else
            d.push_back(a[i]);
    }

    bool ans = true;
    for(int i = 1; i < c.size(); i++) {
        ans &= (c[i] >= c[i - 1]);
    }

    for(int i = 1; i < d.size(); i++) {
        ans &= (d[i] >= d[i - 1]);
    }

    cout << (ans ? "Yes\n" : "No\n");
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}