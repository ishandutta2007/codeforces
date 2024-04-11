
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
using vll = vector<ll>;
using vld = vector<ld>;
using vpll = vector<pll>;
using vvll = vector<vll>;

ll MOD = 998244353;

// Returns {x, y} such that ax+by=gcd(a,b) in O(log(min(a,b))) time.
pll extended_euclid(ll a, ll b){
    if (b == 0) return {1, 0};
    pll p = extended_euclid(b, a % b);
    return {p.second, p.first - a / b * p.second};
}

// Running time O(log(n)).
ll mod_inverse(ll n, ll m = MOD) {return (extended_euclid(n, m).first + m) % m;}

// Interval query data structure.
// When op is a lambda expression, use 'decltype(op)' as template parameter for F.
template <typename T, typename F>
struct segment_tree{
    ll n; vector<T> t; T id; F op;

    segment_tree(ll n_, T id_, F op_) : n(n_), t(2 * n_, id_), id(id_), op(op_) {}

    // Change value i to v in O(log(n)) time.
    void update(ll i, T v){
        for (t[i + n] = v, i = (i + n) / 2; i > 0; i /= 2) t[i] = op(t[2 * i], t[2 * i + 1]);
    }

    // Calculate the combined value from value a up and till value b in O(log(n)) time.
    T query(ll a, ll b){
        T l = id, r = id;
		for (a += n, b += n; a < b; a /= 2, b /= 2) {
			if (a & 1) l = op(l, t[a++]);
			if (!(b & 1)) r = op(t[b--], r);
		}
		return op(a == b ? op(l, t[a]) : l, r);
    }
};

int main(){
    ll n, q;
    cin >> n >> q;
    vll ps(n);
    for (ll i = 0; i < n; ++i){
        cin >> ps[i];
        ps[i] = (100 * mod_inverse(ps[i])) % MOD;
    }
    auto op = [](pll p1, pll p2){return pll((p2.first + p2.second * p1.first) % MOD, (p1.second * p2.second) % MOD);};
    segment_tree<pll, decltype(op)> st(n, pll(0, 1), op);
    for (ll i = 0; i < n; ++i) st.update(i, pll(ps[i], ps[i]));
    set<ll> checks;
    checks.insert(0);
    checks.insert(n);
    ll total = st.query(0, n - 1).first;
    for (ll i = 0; i < q; ++i){
        ll c;
        cin >> c;
        --c;
        auto it = checks.lower_bound(c);
        if (*it == c){
            auto it2 = it;
            ll x = *(--it2);
            ll y = *(it2 = it);
            ll z = *(++it2);
            checks.erase(it);
            total = (total + st.query(x, z - 1).first - st.query(x, y - 1).first - st.query(y, z - 1).first + 2 * MOD) % MOD;
        }
        else{
            auto it2 = it;
            ll x = *(--it2);
            ll y = c;
            ll z = *(++it2);
            checks.insert(c);
            total = (total + st.query(x, y - 1).first + st.query(y, z - 1).first - st.query(x, z - 1).first + MOD) % MOD;
        }
        cout << total << endl;
    }
    return 0;
}