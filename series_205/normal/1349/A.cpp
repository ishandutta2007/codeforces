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

int n, a[200009];

vector<int> vec[200009];

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;

    ll ans = 1;

    rep(i, n) { cin >> a[i]; }

    rep(i, n) {
        for(int j = 2; j * j <= a[i]; j++)
            if(a[i] % j == 0) {
                int x = 0;
                while(a[i] % j == 0) {
                    x++;
                    a[i] /= j;
                }
                vec[j].push_back(x);
            }
        if(a[i] != 1) vec[a[i]].push_back(1);
    }

    FORR(i, 200009) {
        if(vec[i].size() == n) {
            int mn = mod, mn2 = mod;
            for(auto &&v : vec[i]) {
                if(v < mn) {
                    mn2 = mn;
                    mn = v;
                } else {
                    chmin(mn2, v);
                }
            }
            rep(j, mn2) ans *= i;
        } else if(vec[i].size() == n - 1) {
            rep(j, *min_element(ALL(vec[i]))) ans *= i;
        }
    }

    cout << ans << endl;

    return 0;
}