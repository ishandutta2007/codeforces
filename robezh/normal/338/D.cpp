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

typedef long long ll;
const int N = (int)1e4 + 50;

ll n, m;
int k;
ll a[N];
ll pcnt[N];

pll merge(pll p0, pll p1) {
    if(p0.first > p1.first) swap(p0, p1);
    ll r0 = p0.first * p1.first;
    for (ll i = 0; i < p0.first; i++) {
        if((p1.first * i + p1.second - p0.second) % p0.first == 0) {
            return {r0, (p1.first * i + p1.second) % r0};
        }
    }
    assert(false);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;
    ll lcm = 1;
    rep(i, 0, k) {
        cin >> a[i];
        ll g = __gcd(lcm, a[i]);
        ll b = a[i] / g;
        if(lcm >= (n + b) / b) {
            return cout << "NO\n", 0;
        }
        lcm *= b;
        assert(lcm <= n);
    }
    vector<pair<ll, int> > ps;
    ll cm = lcm;
    for (ll i = 2; i * i <= cm; i++) {
        if(cm % i == 0) {
            int ct = 0;
            while(cm % i == 0) cm /= i, ct++;
            ps.push_back({i, ct});
        }
    }
    if(cm > 1) ps.push_back({cm, 1});
    pll dr = {1, 0};
    for (auto &p : ps) {
        int idx = -1;
        ll d2 = 1;
        rep(i, 0, p.second) d2 *= p.first;
        rep(i, 0, k) {
            pcnt[i] = 1; ll x = a[i];
            while(x % p.first == 0) pcnt[i] *= p.first, x /= p.first;
            if(pcnt[i] == d2) idx = i;
        }

        ll rem = (((-idx) % d2) + d2) % d2;
        ll st = rem;
        rep(i, 0, k) {
            ll rc = 1, rm = st;
            while(rc != d2 && rm % p.first == 0) rm /= p.first, rc *= p.first;
            if((++st) >= d2) st -= d2;
            if(pcnt[i] != rc) return cout << "NO\n", 0;
        }
        dr = merge(dr, pll{d2, rem});
    }
    if(dr.second == 0) dr.second += dr.first;
    cout << (dr.second + k - 1 <= m ? "YES" : "NO") << '\n';





}