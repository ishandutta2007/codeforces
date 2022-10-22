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

const int INF = 2e9 + 13;
const li INF64 = 1e18 + 13;
const int N = 2e5 + 13;
const int LOGN = 20;
const int K = 22;
const int M = 1e9 + 7;
//const int M = 998244353;
const int A = 26;
const ld eps = 1e-8;

mt19937 rnd(45768);

/*
*/

void solve() {
    int n, x;
    cin >> n >> x;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<li> mx(n + 1, -INF64);
    mx[0] = 0;
    for(int i = 0; i < n; i++) {
        li cur = 0;
        for(int j = i; j < n; j++) {
            cur += a[j];
            mx[j - i + 1] = max(mx[j - i + 1], cur);
        }
    }

    for(int k = 0; k <= n; k++) {
        li ans = 0;
        for(int i = 0; i <= n; i++) {
            ans = max(ans, mx[i] + x * 1ll * min(k, i));
        }
        cout << ans << ' ';
    }
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}