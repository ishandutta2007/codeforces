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
void solve();

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int t = 1;
    // cin >> t;
    while(t--)
        solve();

    return 0;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    vector<vector<int>> now(n);
    int mn0 = n - 1, mn1 = n - 1;
    set<int> st1, st2;

    FORR(i, n) {
        if(a[i] == 0) continue;
        if(a[i] == 1) {
            while(mn0 >= 0 && now[mn0].size() > 0U)
                mn0--;
            if(mn0 < 0 || now[mn0].size() != 0U) {
                cout << -1 << "\n";
                return;
            }
            now[mn0].push_back(i);
            st1.insert(mn0);
        }
        if(a[i] == 2) {
            while(mn1 >= 0 && now[mn1].size() > 1U)
                mn1--;
            if(mn1 < 0 || now[mn1].size() != 1U) {
                cout << -1 << "\n";
                return;
            }
            now[mn1].push_back(i);
            st1.erase(mn1);
            st2.insert(mn1);
        }
        if(a[i] == 3) {
            while(mn0 >= 0 && now[mn0].size() > 0U)
                mn0--;
            if(mn0 < 0 || now[mn0].size() != 0U) {
                cout << -1 << "\n";
                return;
            }
            int mn2;
            if(!st2.empty()) {
                mn2 = *st2.begin();
                st2.erase(mn2);
            } else if(!st1.empty()) {
                mn2 = *st1.begin();
                st1.erase(mn2);
            } else {
                cout << -1 << "\n";
                return;
            }
            int x = now[mn2].back();
            now[mn2].push_back(-1);
            now[mn0].push_back(x);
            now[mn0].push_back(i);
            st2.insert(mn0);
        }
    }

    int cnt = 0;
    rep(i, n) { cnt += now[i].size() - count(ALL(now[i]), -1); }

    cout << cnt << "\n";
    rep(i, n) for(auto &&x : now[i]) if(x >= 0) cout << i + 1 << " " << x + 1
                                                     << "\n";
}