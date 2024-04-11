#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
template <class T>
using V = vector<T>;
template <class T>
using VV = V<V<T>>;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i, n) rep2(i, 0, n)
#define rep2(i, m, n) for (int i = m; i < (n); i++)
#define per(i, b) per2(i, 0, b)
#define per2(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
#define ALL(c) (c).begin(), (c).end()
#define SZ(x) ((int)(x).size())

constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }

template <class T, class U>
void chmin(T& t, const U& u) {
    if (t > u) t = u;
}
template <class T, class U>
void chmax(T& t, const U& u) {
    if (t < u) t = u;
}

template <class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
    os << "(" << p.first << "," << p.second << ")";
    return os;
}

template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    os << "{";
    rep(i, v.size()) {
        if (i) os << ",";
        os << v[i];
    }
    os << "}";
    return os;
}

#ifdef LOCAL
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << H;
    debug_out(T...);
}
#define debug(...) \
    cerr << __LINE__ << " [" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define dump(x) cerr << __LINE__ << " " << #x << " = " << (x) << endl
#else
#define debug(...) (void(0))
#define dump(x) (void(0))
#endif

const ll LIM = TEN(17);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll x;
    cin >> x;

    V<ll> base;
    base.pb(x);

    V<pair<int, pair<ll, ll>>> ope;

    auto add = [&](ll v) {
        for (auto b : base) chmin(v, v ^ b);
        return v != 0;
    };

    int Q = 100000;

    while (Q) {
        if (find(ALL(base), 1ll) != base.end()) break;
        rep(i, base.size()) {
            rep(j, i + 1) {
                ll x = base[i] + base[j];
                if (x <= LIM && add(x)) {
                    Q--;
                    ope.eb(0, mp(base[i], base[j]));
                    ll v = x;
                    for (auto b : base) {
                        if (v > (v ^ b)) {
                            Q--;
                            ope.eb(1, mp(v, b));
                            v ^= b;
                        }
                    }
                    for (auto& b : base) {
                        if (b > (b ^ v)) {
                            Q--;
                            ope.eb(1, mp(v, b));
                            b ^= v;
                        }
                    }
                    base.pb(v);
                    i = j = 1000000;
                    break;
                }
            }
        }
    }
    cout << ope.size() << endl;
    for (auto v : ope) {
        if (v.fi == 0) {
            cout << v.se.fi << " + " << v.se.se << '\n';
        } else {
            cout << v.se.fi << " ^ " << v.se.se << '\n';
        }
    }

    return 0;
}