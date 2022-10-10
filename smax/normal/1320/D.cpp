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

const uint64_t MOD = (1ULL << 61) - 1;

inline uint64_t add(uint64_t a, uint64_t b) {
    a += b;
    if (a >= MOD)
        a -= MOD;
    return a;
}

inline uint64_t sub(uint64_t a, uint64_t b) {
    a -= b;
    if (a >= MOD)
        a += MOD;
    return a;
}

inline uint64_t mul(uint64_t a, uint64_t b) {
    uint64_t l1 = (uint32_t) a, h1 = a >> 32, l2 = (uint32_t) b, h2 = b >> 32;
    uint64_t l = l1 * l2, m = l1 * h2 + l2 * h1, h = h1 * h2;
    uint64_t ret = (l & MOD) + (l >> 61) + (h << 3) + (m >> 29) + (m << 35 >> 3) + 1;
    ret = (ret & MOD) + (ret >> 61);
    ret = (ret & MOD) + (ret >> 61);
    return ret - 1;
}

int gen() {
    auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
    mt19937 gen(seed ^ uint64_t(new uint64_t));
    uniform_int_distribution<int> dist(258, 2e9 - 1);
    int base = dist(gen);
    return base % 2 == 0 ? base - 1 : base;
}

const int BASE = gen();

uint64_t pw[200005], inv;

struct Node {
    int first, last, sz;
    uint64_t hsh;

    void leaf(int val) {
        first = last = val - '0';
        hsh = val;
        sz = 1;
    }

    void pull(Node a, Node b) {
        if (a.last == 1 && b.first == 1) {
            if (a.sz == 1)
                a.first = a.last = -1;
            else
                a.last = 0;
            a.hsh = mul(sub(a.hsh, '1'), inv);
            a.sz--;
            if (b.sz == 1)
                b.first = b.last = -1;
            else
                b.first = 0;
            b.hsh = sub(b.hsh, mul(pw[b.sz - 1], '1'));
            b.sz--;
        }
        first = a.first == -1 ? b.first : a.first;
        last = b.last == -1 ? a.last : b.last;
        hsh = add(mul(a.hsh, pw[b.sz]), b.hsh);
        sz = a.sz + b.sz;
    }
};

struct SegmentTree {
    int n;
    string s;
    vector<Node> st;

    SegmentTree(int _n) : n(_n), s(n, ' '), st(4*n) {
        build(1, 0, n-1);
    }

    SegmentTree(const string &_s) : n((int) _s.size()), s(_s), st(4*n) {
        build(1, 0, n-1);
    }

    void build(int p, int l, int r) {
        if (l == r) {
            st[p].leaf(s[l]);
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

    uint64_t query(int i, int j) {
        return query(1, 0, n-1, i, j).hsh;
    }

    void update(int p, int l, int r, int idx, int val) {
        if (l == r) {
            st[p].leaf(val);
            return;
        }
        int m = (l + r) / 2;
        if (idx <= m)
            update(2*p, l, m, idx, val);
        else
            update(2*p+1, m+1, r, idx, val);
        st[p].pull(st[2*p], st[2*p+1]);
    }

    void update(int idx, int val) {
        update(1, 0, n-1, idx, val);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    inv = 1;
    uint64_t a = BASE;
    for (uint64_t b=MOD-2; b>0; b/=2) {
        if (b % 2) inv = mul(inv, a);
        a = mul(a, a);
    }

    int n;
    string t;
    cin >> n >> t;

    pw[0] = 1;
    for (int i=1; i<n; i++)
        pw[i] = mul(pw[i-1], BASE);
    SegmentTree st(t);

    int q;
    cin >> q;
    for (int i=0; i<q; i++) {
        int l1, l2, len;
        cin >> l1 >> l2 >> len;
        l1--, l2--;
        cout << (st.query(l1, l1 + len - 1) == st.query(l2, l2 + len - 1) ? "Yes" : "No") << "\n";
    }

    return 0;
}