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
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 2);
    FOR(i, 1, n + 1) cin >> a[i];

    ll ans = 0;
    set<int> p, m;
    FOR(i, 1, n + 1) {
        if(a[i - 1] < a[i] && a[i] > a[i + 1]) {
            ans += a[i];
            p.insert(i);
        }
        if(!p.empty() && a[i - 1] > a[i] && a[i] < a[i + 1]) {
            ans -= a[i];
            m.insert(i);
        }
    }

    cout << ans << "\n";

    while(q--) {
        int l, r;
        cin >> l >> r;
        vector<int> ids;
        FOR(i, -1, 2) {
            ids.push_back(l + i);
            ids.push_back(r + i);
        }
        sort(ALL(ids));
        ids.erase(unique(ALL(ids)), ids.end());
        for(int i : ids) {
            if(p.count(i)) {
                p.erase(i);
                ans -= a[i];
            }
            if(m.count(i)) {
                m.erase(i);
                ans += a[i];
            }
        }
        swap(a[l], a[r]);
        for(int i : ids) {
            if(a[i - 1] < a[i] && a[i] > a[i + 1]) {
                ans += a[i];
                p.insert(i);
            }
            if(*p.begin() < i && a[i - 1] > a[i] && a[i] < a[i + 1]) {
                ans -= a[i];
                m.insert(i);
            }
        }
        cout << ans << "\n";
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