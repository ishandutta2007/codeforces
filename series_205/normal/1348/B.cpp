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

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    vector<int> a, cnt;
    while(t--) {
        int n, k;
        cin >> n >> k;
        a.resize(n);
        cnt.assign(n + 1, 0);
        rep(i, n) cin >> a[i], cnt[a[i]]++;
        vector<int> cnt2;
        FOR(i, 1, n + 1) if(cnt[i]) cnt2.push_back(i);
        if(cnt2.size() > k) {
            cout << -1 << "\n";
            continue;
        }
        cout << 10000 << "\n";
        rep(i, 10000) cout << cnt2[(i % k) % cnt2.size()] << " \n"[i == 9999];
    }
    cout << flush;

    return 0;
}