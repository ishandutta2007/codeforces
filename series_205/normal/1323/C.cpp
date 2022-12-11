#include <bits/stdc++.h>
#define FOR(i, a, n) for(ll i = (ll)a; i < (ll)n; i++)
#define rep(i, n) FOR(i, 0, n)
#define ALL(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;

constexpr ll Mod = 998244353;
constexpr ll mod = 1e9 + 7;
constexpr ll inf = 1LL << 60;

template <typename T> constexpr bool chmax(T &a, const T b) {
    if(a >= b) return false;
    a = b;
    return true;
}
template <typename T> constexpr bool chmin(T &a, const T b) {
    if(a <= b) return false;
    a = b;
    return true;
}

/*-------------------------------------------*/

int n;
string s;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n >> s;
    vector<int> sum(n + 1, 0);
    int ans = 0;
    int cnt = 0;
    rep(i, n) {
        sum[i + 1] = sum[i] + (s[i] == '(' ? 1 : -1);
        if(sum[i + 1] < 0)
            cnt++;
        else if(cnt) {
            ans += cnt + 1;
            cnt = 0;
        }
    }
    if(sum[n] != 0) {
        cout << -1 << endl;
        return 0;
    }
    cout << ans << endl;
    return 0;
}