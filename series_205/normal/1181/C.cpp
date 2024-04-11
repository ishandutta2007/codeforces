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

int h, w;
char c[1009][1009];

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> h >> w;
    rep(i, h) cin >> c[i];

    ll ans = 0;
    vector<vector<tuple<char, char, char, int>>> a(
        h, vector<tuple<char, char, char, int>>(w, make_tuple(-1, -1, -1, -1)));
    rep(j, w) {
        vector<pair<char, int>> vec;
        rep(i, h) {
            if(i == 0 || c[i][j] != c[i - 1][j]) vec.emplace_back(c[i][j], 0);
            vec.back().second++;
        }
        int sum = vec[0].second;
        FOR(i, 1, (int)vec.size() - 1) {
            if(vec[i - 1].second >= vec[i].second &&
               vec[i].second <= vec[i + 1].second) {
                a[sum][j] = make_tuple(vec[i - 1].first, vec[i].first,
                                       vec[i + 1].first, vec[i].second);
            }
            sum += vec[i].second;
        }
    }

    rep(i, h) {
        for(int j = 0, k = 0; j < w; j = k) {
            while(k < w && a[i][j] == a[i][k]) k++;
            if(a[i][j] == make_tuple(-1, -1, -1, -1)) continue;
            ans += (k - j) * (k - j + 1) / 2;
        }
    }

    cout << ans << endl;

    return 0;
}