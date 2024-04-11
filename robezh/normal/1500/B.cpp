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

ll gcd(ll a, ll b) { return __gcd(a, b); }

ll euclid(ll a, ll b, ll &x, ll &y) {
    if (b) { ll d = euclid(b, a % b, y, x);
        return y -= a/b * x, d; }
    return x = 1, y = 0, a;
}


template<class Z> Z chinese(Z a, Z m, Z b, Z n) {
    Z x, y; euclid(m, n, x, y);
    Z ret = a * (y + m) % m * n + b * (x + n) % n * m;
    if (ret >= m * n) ret -= m * n;
    return ret;
}

template<class Z> Z chinese_common(Z a, Z m, Z b, Z n) {
    Z d = gcd(m, n);
    if (((b -= a) %= n) < 0) b += n;
    if (b % d) return -1; // No solution
    return d * chinese(Z(0), m/d, b/d, n/d) + a;
}

const int N = (int)1e6 + 50;

int n, m;
ll k;
int l1[N], l2[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;
    memset(l1, -1, sizeof l1);
    memset(l2, -1, sizeof l2);
    rep(i, 0, n) {
        int x; cin >> x;
        l1[x] = i;
    }
    rep(i, 0, m) {
        int x; cin >> x;
        l2[x] = i;
    }
    vector<ll> rs;
    ll lcm = 1LL * n * m / __gcd(n, m);
    rep(i, 1, 2 * max(n, m) + 1) {
        if(l1[i] != -1 && l2[i] != -1) {
            ll rem = chinese_common((ll)l1[i], (ll)n, (ll)l2[i], (ll)m);
            if(rem == -1) continue;
            rs.push_back(rem);
        }
    }
    ll l = 0, r = (ll)1e18 + 5, mid;
    while(l + 1 < r) {
        mid = (l + r) / 2;
        ll c = mid;
        for (auto &rem : rs) c -= (mid - 1 - rem + lcm) / lcm;
        if(c >= k) r = mid;
        else l = mid;
    }
    cout << r << '\n';




}