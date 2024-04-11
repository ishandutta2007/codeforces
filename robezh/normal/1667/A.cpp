#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define subnb true
#define Lnb true
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const int N = 5005;

int n;
ll a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    rep(i, 0, n) cin >> a[i];
    ll res = (ll)1e18;
    rep(i, 0, n) {
        ll c = 0;
        ll cnt = 0;
        for (int j = i - 1; j >= 0; j--) {
            ll nxt = (c / a[j] + 1) * a[j];
            cnt += c / a[j] + 1;
            c = nxt;
        }
        c = 0;
        rep(j, i + 1, n) {
            ll nxt = (c / a[j] + 1) * a[j];
            cnt += c / a[j] + 1;
            c = nxt;
        }
        res = min(res, cnt);
    }
    cout << res << '\n';



}