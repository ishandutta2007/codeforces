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

void put(ll x) { cout << bitset<10>(x) << endl; }
void test() {
    set<ll> st;
    for (ll a = 1; a <= 100; ++a) {
        for (ll b = 1; b <= 100; ++b) {
            if (st.count(a) || st.count(b) || st.count(b ^ a)) continue;
            if (b != a) {
                put(a);
                put(b);
                put(a ^ b);
                cout << "------------\n";
                st.insert(a);
                st.insert(b);
                st.insert(a ^ b);
                break;
            }
        }
    }
}

const ll fa[4] = {0, 1, 2, 3};
const ll fb[4] = {0, 2, 3, 1};
const ll fc[4] = {0, 3, 1, 2};

ll solve(ll n) {
    ll num = (n - 1) / 3, pos = (n - 1) % 3;
    ll cur = 0;
    for (int l = 0;; l += 2) {
        ll call = 1ll << l;
        if (num >= call) {
            num -= call;
            continue;
        }
        ll a = 1ll << l;
        ll b = 1ll << (l + 1);
        ll c = 3ll << l;
        for (int u = l - 2; u >= 0; u -= 2) {
            per(v, 4) {
                ll x = (1ll << u) * v;
                if (num >= x) {
                    num -= x;
                    a += (1ll << u) * fa[v];
                    b += (1ll << u) * fb[v];
                    c += (1ll << u) * fc[v];
                }
            }
        }
        //  debug(a, b, c);
        return (pos == 0 ? a : (pos == 1 ? b : c));
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        cout << solve(n) << endl;
    }
    return 0;
}