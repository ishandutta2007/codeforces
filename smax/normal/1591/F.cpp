// https://atcoder.jp/contests/arc115/tasks/arc115_e
// https://atcoder.jp/contests/arc115/submissions/21232819
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

struct Node {
    int l, r, sz;
    M ans = 0, mul = 1, add = 0;

    void leaf(int _sz) {
        sz = _sz;
    }

    void pull(Node &a, Node &b) {
        ans = a.ans + b.ans;
        sz = a.sz + b.sz;
    }

    void push(M m, M c) {
        mul *= m;
        add *= m;
        add += c;
    }

    void apply() {
        ans *= mul;
        ans += add * sz;
        mul = 1;
        add = 0;
    }
};

struct SegmentTree {
    int n;
    vector<int> a;
    vector<Node> st;

    SegmentTree(int _n) : n(_n), a(n), st(4*n) {
        build(1, 0, n-1);
    }

    SegmentTree(const vector<int> &_a) : n((int) _a.size()), a(_a), st(4*n) {
        build(1, 0, n-1);
    }

    void build(int p, int l, int r) {
        st[p].l = l;
        st[p].r = r;
        if (l == r) {
            st[p].leaf(a[l]);
            return;
        }
        int m = (l + r) / 2;
        build(2*p, l, m);
        build(2*p+1, m+1, r);
        st[p].pull(st[2*p], st[2*p+1]);
    }

    void push(int p) {
        if (st[p].mul != 1 || st[p].add != 0) {
            if (st[p].l != st[p].r) {
                st[2*p].push(st[p].mul, st[p].add);
                st[2*p+1].push(st[p].mul, st[p].add);
            }
            st[p].apply();
        }
    }

    Node query(int p, int i, int j) {
        push(p);
        if (st[p].l == i && st[p].r == j)
            return st[p];
        int m = (st[p].l + st[p].r) / 2;
        if (j <= m)
            return query(2*p, i, j);
        else if (i > m)
            return query(2*p+1, i, j);
        Node ret, ls = query(2*p, i, m), rs = query(2*p+1, m+1, j);
        ret.pull(ls, rs);
        return ret;
    }

    M query(int i, int j) {
        return query(1, i, j).ans;
    }

    void update(int p, int i, int j, M mul, M add) {
        if (st[p].l == i && st[p].r == j) {
            st[p].push(mul, add);
            push(p);
            return;
        }
        push(p);
        int m = (st[p].l + st[p].r) / 2;
        if (j <= m) {
            update(2*p, i, j, mul, add);
            push(2*p+1);
        } else if (i > m) {
            push(2*p);
            update(2*p+1, i, j, mul, add);
        } else {
            update(2*p, i, m, mul, add);
            update(2*p+1, m+1, j, mul, add);
        }
        st[p].pull(st[2*p], st[2*p+1]);
    }

    void update(int i, int j, M mul, M add) {
        update(1, i, j, mul, add);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> a(n), sorted(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
        sorted[i] = a[i];
    }

    sort(sorted.begin(), sorted.end());
    sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());
    for (int i=0; i<n; i++)
        a[i] = int(lower_bound(sorted.begin(), sorted.end(), a[i]) - sorted.begin());
    for (int i=(int)sorted.size()-1; i>0; i--)
        sorted[i] -= sorted[i-1];

    SegmentTree st(sorted);
    st.update(0, a[0], 1, 1);
    for (int i=1; i<n; i++) {
        M tot = st.st[1].ans;
        st.update(0, a[i], -1, tot);
        if (a[i] + 1 < st.n)
            st.update(a[i] + 1, st.n - 1, 0, 0);
    }
    cout << st.st[1].ans << "\n";

    return 0;
}