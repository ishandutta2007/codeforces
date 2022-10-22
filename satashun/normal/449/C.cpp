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

const int MX = 100010;

bool pr[MX];
V<int> vp;

void sieve() {
    for (int i = 0; i < MX; ++i) {
        pr[i] = 1;
    }
    pr[0] = pr[1] = 0;
    for (int i = 2; i < MX; ++i) {
        if (pr[i]) {
            vp.pb(i);
            for (int j = i * 2; j < MX; j += i) {
                pr[j] = 0;
            }
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    sieve();
    reverse(ALL(vp));

    int n;
    cin >> n;
    V<bool> e(n + 1);
    for (int i = 1; i <= n; ++i) e[i] = true;

    V<pii> vec;

    for (int p : vp) {
        if (p * 2 <= n) {
            debug(p);
            // intact
            V<int> v = {p * 2, p};
            for (int i = p * 3; i <= n; i += p) {
                if (e[i]) v.pb(i);
            }
            reverse(ALL(v));
            for (int i = 0; i + 2 <= v.size(); i += 2) {
                int a = v[i], b = v[i + 1];
                vec.eb(a, b);
                e[a] = 0;
                e[b] = 0;
            }
        }
    }

    cout << vec.size() << '\n';
    for (auto p : vec) {
        cout << p.fi << ' ' << p.se << '\n';
    }

    return 0;
}