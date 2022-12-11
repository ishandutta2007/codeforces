#include <bits/stdc++.h>
#define FOR(i, a, n) for(ll i = (ll)a; i < (ll)n; i++)
#define FORR(i, n) for(ll i = (ll)n - 1LL; i >= 0LL; i--)
#define rep(i, n) FOR(i, 0, n)
#define ALL(x) begin(x), end(x)
using namespace std;
using ll = long long;
template <typename T> using V = vector<T>;
constexpr int Mod = 998244353;
constexpr int mod = 1e9 + 7;
constexpr ll inf = 1LL << 60;
const double PI = acos(-1);
template <typename T> constexpr bool chmax(T &a, const T &b) {
    if(a >= b) return false;
    a = b;
    return true;
}
template <typename T> constexpr bool chmin(T &a, const T &b) {
    if(a <= b) return false;
    a = b;
    return true;
}

/*-------------------------------------------*/

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        int n = s.size();
        vector<int> a[3] = {{-1}, {-1}, {-1}};
        rep(i, n) a[s[i] - '1'].push_back(i);
        if(a[0].size() == 1 || a[1].size() == 1 || a[2].size() == 1) {
            cout << "0\n";
            continue;
        }
        rep(i, 3) a[i].push_back(mod);
        int ans = mod;
        FOR(i, -1, n) {
            int num = 0;
            rep(j, 3) chmax<int>(num, *upper_bound(ALL(a[j]), i) - i);
            chmin(ans, num);
        }
        cout << ans << "\n";
    }

    return 0;
}