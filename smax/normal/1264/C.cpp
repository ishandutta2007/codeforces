#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__)
#else
#define DEBUG(...) 6
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << s << " = " << x << "\n";}
template <typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++; else
if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << s.substr(0, i) << " = " << x << " | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}

template<int MOD>
struct ModInt {
    long long v;
    ModInt(long long _v = 0) {v = (-MOD < _v && _v < MOD) ? _v : _v % MOD; if (v < 0) v += MOD;}
    ModInt& operator += (const ModInt &other) {v += other.v; if (v >= MOD) v -= MOD; return *this;}
    ModInt& operator -= (const ModInt &other) {v -= other.v; if (v < 0) v += MOD; return *this;}
    ModInt& operator *= (const ModInt &other) {v = v * other.v % MOD; return *this;}
    ModInt& operator /= (const ModInt &other) {return *this *= inverse(other);}
    bool operator == (const ModInt &other) const {return v == other.v;}
    bool operator != (const ModInt &other) const {return v != other.v;}
    friend ModInt operator + (ModInt a, const ModInt &b) {return a += b;}
    friend ModInt operator - (ModInt a, const ModInt &b) {return a -= b;}
    friend ModInt operator * (ModInt a, const ModInt &b) {return a *= b;}
    friend ModInt operator / (ModInt a, const ModInt &b) {return a /= b;}
    friend ModInt operator - (const ModInt &a) {return 0 - a;}
    friend ModInt power(ModInt a, long long b) {ModInt ret(1); while (b > 0) {if (b & 1) ret *= a; a *= a; b >>= 1;} return ret;}
    friend ModInt inverse(ModInt a) {return power(a, MOD - 2);}
    friend ostream& operator << (ostream &os, const ModInt &m) {return os << m.v;}
};
typedef ModInt<998244353> M;

// (A, B)
// A_i = 1 + p_i * A_{i+1}
// B_i = 1 - p_i + p_i * B_{i+1}
struct Node {
    M ac, am, bc, bm;

    void leaf(M p) {
        ac = 1;
        am = bm = p;
        bc = 1 - p;
    }

    void pull(Node &a, Node &b) {
        ac = a.ac + a.am * b.ac;
        am = a.am * b.am;
        bc = a.bc + a.bm * b.bc;
        bm = a.bm * b.bm;
    }
};

struct SegmentTree {
    int n;
    vector<M> a;
    vector<Node> st;

    SegmentTree(int _n) : n(_n), st(4*n) {
        build(1, 0, n-1);
    }

    SegmentTree(const vector<M> &_a) : n((int) _a.size()), a(_a), st(4*n) {
        build(1, 0, n-1);
    }

    void build(int p, int l, int r) {
        if (l == r) {
            st[p].leaf(a[l]);
            return;
        }
        int m = (l + r) / 2;
        build(2*p, l, m);
        build(2*p+1, m+1, r);
        st[p].pull(st[2*p], st[2*p+1]);
    }

    Node query(int p, int l, int r, int i, int j) {
        if (l == i && r == j)
            return st[p];
        int m = (l + r) / 2;
        if (j <= m)
            return query(2*p, l, m, i, j);
        else if (i > m)
            return query(2*p+1, m+1, r, i, j);
        Node ret, ls = query(2*p, l, m, i, m), rs = query(2*p+1, m+1, r, m+1, j);
        ret.pull(ls, rs);
        return ret;
    }

    Node query(int i, int j) {
        return query(1, 0, n-1, i, j);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;
    vector<M> p(n);
    for (int i=0; i<n; i++) {
        int x;
        cin >> x;
        p[i] = M(x) / 100;
    }

    // E = A + B * E
    // (1 - B) * E = A
    // E = A / (1 - B)
    SegmentTree st(p);

    auto query = [&] (int l, int r) -> M {
        Node cur = st.query(l, r - 1);
        return cur.ac / (1 - cur.bc);
    };

    set<int> ckpt{0, n};
    M ret = query(0, n);
    for (int i=0; i<q; i++) {
        int u;
        cin >> u;
        u--;
        auto [it, b] = ckpt.insert(u);
        if (b) {
            ret += query(*prev(it), u) + query(u, *next(it)) - query(*prev(it), *next(it));
        } else {
            ret += query(*prev(it), *next(it)) - query(*prev(it), u) - query(u, *next(it));
            ckpt.erase(it);
        }
        cout << ret << "\n";
    }

    return 0;
}