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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    ll n, m, k;
    cin >> n >> m >> k;
    vector<int> a, b;

    int cnt = 0;
    rep(i, n) {
        int A;
        cin >> A;
        if(A)
            cnt++;
        else if(cnt) {
            a.push_back(cnt);
            cnt = 0;
        }
    }
    if(cnt) a.push_back(cnt);
    cnt = 0;
    rep(i, m) {
        int B;
        cin >> B;
        if(B)
            cnt++;
        else if(cnt) {
            b.push_back(cnt);
            cnt = 0;
        }
    }
    if(cnt) b.push_back(cnt);

    ll ans = 0;
    for(ll i = 1; i * i <= k; i++) {
        if(k % i) continue;
        ll j = k / i;
        rep(x, 2) {
            ll A = 0, B = 0;
            rep(l, a.size()) A += max(0ll, a[l] - i + 1);
            rep(l, b.size()) B += max(0ll, b[l] - j + 1);
            ans += A * B;
            if(i == j) break;
            swap(i, j);
        }
    }
    cout << ans << endl;

    return 0;
}