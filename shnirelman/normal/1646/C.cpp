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
const int N = 2e5 + 13;
const int LOGN = 20;
const int K = 22;
const int M = 998244353;//1e9 + 7;
const int A = 26;
const ld eps = 1e-8;

mt19937 rnd(45768);

/*
*/

void solve() {
    li n;
    cin >> n;

    vector<li> f(1, 6);
    int cur = 4;
    while(f.back() <= n) {
        f.push_back(f.back() * (cur++));
    }
    f.pop_back();
//
//    for(auto x : f)
//        cout << x << ' ';
//    cout << endl;

    int ans = __builtin_popcountll(n);
    for(int mask = 0; mask < (1 << f.size()); mask++) {
        li sum = 0;
        for(int i = 0; i < f.size(); i++)
            if(mask & (1 << i))
                sum += f[i];

        if(sum > n)
            continue;

//        cout << mask << ' ' << sum << ' ' << __builtin_popcountll(n - sum) << endl;
        ans = min(ans, __builtin_popcountll(n - sum) + __builtin_popcount(mask));
    }

    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}