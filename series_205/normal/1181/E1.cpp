#include <bits/stdc++.h>
// #include <atcoder/all>
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
template <typename T1, typename T2>
inline bool chmax(T1 &a, T2 b) {
    return a < b && (a = b, true);
}
template <typename T1, typename T2>
inline bool chmin(T1 &a, T2 b) {
    return a > b && (a = b, true);
}
/*-------------------------------------------*/

int n;
ll a[1009], b[1009], c[1009], d[1009];

bool solve(vector<int> p) {
    if(p.size() == 1) return true;
    for(auto i : p) {
        int x = a[i];
        bool flag = false;
        bool ok1 = false;
        for(auto i : p) {
            if(a[i] < x && x < c[i]) flag = true;
            if(c[i] <= x) ok1 = true;
        }
        if(flag || !ok1) continue;
        vector<int> p1, p2;
        for(auto i : p) {
            if(c[i] <= x)
                p1.push_back(i);
            else
                p2.push_back(i);
        }
        return solve(p1) && solve(p2);
    }
    for(auto i : p) {
        int y = b[i];
        bool flag = false;
        bool ok1 = false;
        for(auto i : p) {
            if(b[i] < y && y < d[i]) flag = true;
            if(d[i] <= y) ok1 = true;
        }
        if(flag || !ok1) continue;
        vector<int> p1, p2;
        for(auto i : p) {
            if(d[i] <= y)
                p1.push_back(i);
            else
                p2.push_back(i);
        }
        return solve(p1) && solve(p2);
    }
    return false;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    rep(i, n) cin >> a[i] >> b[i] >> c[i] >> d[i];

    vector<int> p(n);
    iota(ALL(p), 0);

    cout << (solve(p) ? "YES" : "NO") << endl;

    return 0;
}