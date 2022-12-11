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

int n;
ll k, a[100009];

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while(t--) {
        cin >> n >> k;
        rep(i, n) cin >> a[i];
        if(count(a, a + n, k) == 0) {
            cout << "no\n";
            continue;
        }
        if(n == 1) {
            cout << "yes\n";
            continue;
        }
        rep(i, n - 1) {
            if(a[i] >= k && a[i + 1] >= k) {
                cout << "yes\n";
                goto nxt;
            }
        }
        rep(i, n - 2) {
            if(a[i] >= k && a[i + 2] >= k) {
                cout << "yes\n";
                goto nxt;
            }
        }
        cout << "no\n";
    nxt:;
    }
    cout << flush;

    return 0;
}