// #include <atcoder/all>
#include <bits/stdc++.h>
#define FOR(i, a, n) for(ll i = (ll)a; i < (ll)n; i++)
#define FORR(i, n) for(ll i = (ll)n - 1LL; i >= 0LL; i--)
#define rep(i, n) FOR(i, 0, n)
#define ALL(x) begin(x), end(x)
using namespace std;
using ll = long long;
constexpr ll Mod = 998244353;
constexpr ll mod = 1e9 + 7;
constexpr ll inf = 1LL << 60;
const double PI = acos(-1);
template <typename T1, typename T2> inline bool chmax(T1 &a, T2 b) {
    return a < b && (a = b, true);
}
template <typename T1, typename T2> inline bool chmin(T1 &a, T2 b) {
    return a > b && (a = b, true);
}
/*-------------------------------------------*/

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int sum = 0;
    rep(i, n) {
        cin >> a[i];
        sum += a[i];
    }
    if(sum % n != 0) {
        cout << "-1\n";
        return;
    }
    sum /= n;
    vector<array<int, 3>> ans;
    FOR(i, 1, n) {
        int j = i + 1;
        int x = (j - a[i] % j) % j;
        ans.push_back({1, j, x});
        a[0] -= x;
        a[i] += x;
        ans.push_back({j, 1, a[i] / j});
        a[0] += a[i];
        a[i] = 0;
    }
    FOR(i, 1, n) ans.push_back({1, i + 1, sum});
    cout << ans.size() << "\n";
    for(auto &&ar : ans) {
        cout << ar[0] << " " << ar[1] << " " << ar[2] << "\n";
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while(t--)
        solve();

    return 0;
}