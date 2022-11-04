#include "bits/stdc++.h"

using namespace std;

template<typename A, typename B>
string to_string(pair<A, B> p);

template<typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);

template<typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);

string to_string(const string &s) { return '"' + s + '"'; }

string to_string(const char *s) { return to_string((string) s); }

string to_string(char s) {
    string str(1, s);
    return str;
}
string to_string(bool b) { return (b ? "true" : "false"); }

string to_string(vector<bool> v) {
    bool first = true;
    string res = "{";
    for (int i = 0; i < static_cast<int>(v.size()); i++) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(v[i]);
    }
    res += "}";
    return res;
}

template<size_t N>
string to_string(bitset<N> v) {
    string res = "";
    for (size_t i = 0; i < N; i++) {
        res += static_cast<char>('0' + v[i]);
    }
    return res;
}

template<typename A>
string to_string(A v) {
    bool first = true;
    string res = "{";
    for (const auto &x : v) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}

template<typename A, typename B>
string to_string(pair<A, B> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template<typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " +
           to_string(get<2>(p)) + ")";
}

template<typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " +
           to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}

void debug_out() { cerr << endl; }

template<typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << to_string(H);
    debug_out(T...);
}

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...)
#endif

#define sz(a) (ll)((a).size())
#define all(v) (v).begin(), (v).end()
#define rall(v) v.rbegin(), v.rend()
#define pikachu push_back
#define mp make_pair
#define st first
#define nd second
#define i128 __int128
//#define pt(s) (s)[sz((s)) - 2]
#define pll pair<ll, ll>
#define pii pair<int, int>

mt19937 rnd((uint32_t)chrono::high_resolution_clock::now().time_since_epoch().count());
std::istream &operator>>(std::istream &in, i128 &a) {
    long long kek2;
    in >> kek2;
    a = kek2;
    return in;
}
std::ostream &operator<<(std::ostream &out, const i128 &a) {
    string res;
    i128 val = a;
    if (val == 0) {
        out << 0;
        return out;
    }
    if (val < 0)
        out << '-', val = -val;
    while (val)
        res.pikachu(val % 10 + '0'), val /= 10;
    reverse(all(res));
    out << res;
    return out;
}
template<class t1, class t2>
inline bool cmin(t1 &a, const t2 &b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

template<class t1, class t2>
inline bool cmax(t1 &a, const t2 &b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef long double ld;

template<typename Arr, typename TVal>
void MyFill(Arr &a, TVal val, size_t n) {
    for (size_t i = 0; i < n; ++i)
        a[i] = val;
}
template<typename Arr, typename TVal, typename... Tail>
void MyFill(Arr &a, TVal val, size_t n, Tail... T) {
    for (size_t i = 0; i < n; ++i)
        MyFill(a[i], val, T...);
}

inline ull bpow(ull a, ull b, ull mod) {
    ull res = 1;
    for (; b; b >>= 1) {
        if (b & 1) {
            res = ((ull) res * a) % mod;
        }
        a = ((ull) a * a) % mod;
    }
    return res;
}
struct HASH {
    size_t operator()(const pll &p) const {
        return p.st ^ p.nd;
    }
};

struct NegativeInfType;

struct PositiveInfType {
    static constexpr int int_inf = static_cast<int>(2e9 + 666);
    static constexpr ll ll_inf = (ll) 3e18 + 666;

    operator int() const {
        return int_inf;
    }

    operator long long() const {
        return ll_inf;
    }

    NegativeInfType operator-() const;
} const INF;

struct NegativeInfType {
    operator int() const {
        return -(int) (INF);
    }

    operator long long() const {
        return -(long long) (INF);
    }
};

NegativeInfType PositiveInfType::operator-() const {
    return {};
}

template<class T>
bool operator==(T val, const PositiveInfType &inf) {
    return val == T(inf);
}

template<class T>
bool operator==(T val, const NegativeInfType &neg_inf) {
    return val == T(neg_inf);
}

#ifndef LOCAL
void UseFiles(const string &s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}
#else
void UseFiles(const string &s) {}
#endif

void run();
signed main() {
    iostream::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(30) << fixed;
    //UseFiles("freedom");
    run();
}
const ll N = ll(1e5) + 2;

inline ll divup(ll a, ll b) {
    // if (b < 0) {
    //     a = -a;
    //     b = -b;
    // }
    ll res = a / b;
    if (a % b > 0) {
        ++res;
    }
    return res;
}

// inline ll divup(ll a, ll b) {
//     return ceil(1. * a / b);
// }

inline ll X(pll l1, pll l2) {
    return divup(l2.nd - l1.nd, l1.st - l2.st);
}

struct CHT {
    vector<pll> line;
    vector<ll> point;
    int rk = -1;
 
    CHT() {}
 
    CHT(pll l) {
        rk = 0;
        point.pikachu(-INF);
        line.pikachu(l);
    }
 
    bool check(pll l) {
        if (line.back().st == l.st) return true;
        return X(line.back(), l) <= point.back();
    }
 
    void add(pll l) {
        while (sz(line) && check(l)) line.pop_back(), point.pop_back();
        if (!sz(line))
            point.pikachu(-INF);
        else
            point.pikachu(X(line.back(), l));
        line.pikachu(l);
    }
 
    void clear() {
        rk = -1;
        line.clear();
        point.clear();
    }
 
    size_t size() const {
        return line.size();
    }
 
    ll get(ll x) const {
        ll num = upper_bound(all(point), x) - point.begin() - 1;
        return line[num].st * x + line[num].nd;
    }
};

int kek_cnt = 0;

void MergeInplace(CHT& a, const CHT& b) {
    assert(a.rk == b.rk);
    assert(a.rk != -1);

    vector<pll> lines;
    lines.reserve(sz(a.line) + sz(b.line));
    merge(all(a.line), all(b.line), back_inserter(lines), greater<pll>());
    a.clear();

    for (auto line : lines) {
        a.add(line);
    }

    a.rk = b.rk;

    if (a.size() > (1 << a.rk)) {
        ++a.rk;
    } else {
        ++kek_cnt;
    }
}

CHT merge(const CHT &a, const CHT &b) {
    auto result = a;
    MergeInplace(result, b);
    return result;
}

struct LiChao {
    int len = 0;
    vector<CHT> kek;
    int size() const {
        return kek.size();
    }
    void add(const CHT &c) {
        len += c.size();
        kek.pikachu(c);
        ll i = sz(kek) - 1;
        while (i > 0 && kek[i].rk > kek[i - 1].rk) swap(kek[i], kek[i - 1]), --i;
        while (i > 0 && kek[i].rk == kek[i - 1].rk) {
            MergeInplace(kek[i - 1], kek[i]);
            // kek[i - 1] = merge(kek[i], kek[i - 1]);
            kek[i].clear();
            --i;
        }
        erase_if(kek, [](const CHT &x) { return x.rk == -1; });
    }
    ll get(ll x) const {
        ll ans = INF;
        for (auto &e : kek) {
            cmin(ans, e.get(x));
        }
        return ans;
    }
};
LiChao merge(LiChao&& a, LiChao&& b) {
    if (sz(a) < sz(b)) swap(a, b);
    reverse(all(b.kek));
    for (auto &c : b.kek) a.add(c);
    return a;
}
vector<int> g[N];
ll a[N], b[N], dp[N];

LiChao dfs(ll v, ll p) {
    LiChao T;
    for (auto u : g[v]) {
        if (u == p) continue;
        T = merge(move(T), dfs(u, v));
    }
    dp[v] = T.get(a[v]);
    if (sz(T) == 0) dp[v] = 0;
    T.add(CHT({ b[v], dp[v] }));
    return T;
}
void run() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];
    for (int i = 1; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        --x, --y;
        g[x].pikachu(y);
        g[y].pikachu(x);
    }
    dfs(0, -1);
    for (int i = 0; i < n; ++i) cout << dp[i] << ' ';
    cerr << "Kek_cnt: " << kek_cnt << endl;
}