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
template<typename T> void debug(string s, T x) {cerr << "\033[1;35m" << s << "\033[0;32m = \033[33m" << x << "\033[0m\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++; else
if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << "\033[1;35m" << s.substr(0, i) << "\033[0;32m = \033[33m" << x << "\033[31m | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}

using ull = unsigned long long;

const ull MOD = (1ULL << 61) - 1;

ull add(ull a, ull b) {
    a += b;
    if (a >= MOD)
        a -= MOD;
    return a;
}

ull sub(ull a, ull b) {
    a -= b;
    if (a >= MOD)
        a += MOD;
    return a;
}

ull mul(ull a, ull b) {
    ull l1 = (uint32_t) a, h1 = a >> 32, l2 = (uint32_t) b, h2 = b >> 32;
    ull l = l1 * l2, m = l1 * h2 + l2 * h1, h = h1 * h2;
    ull ret = (l & MOD) + (l >> 61) + (h << 3) + (m >> 29) + (m << 35 >> 3) + 1;
    ret = (ret & MOD) + (ret >> 61);
    ret = (ret & MOD) + (ret >> 61);
    return ret - 1;
}

ull inverse(ull a) {
    ull ret = 1;
    for (ull b=MOD-2; b>0; b/=2) {
        if (b % 2) ret = mul(ret, a);
        a = mul(a, a);
    }
    return ret;
}

int gen() {
    auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
    mt19937 gen(seed ^ ull(new ull));
    uniform_int_distribution<int> dist(1e5 + 1, 2e9 - 1);
    int base = dist(gen);
    return base % 2 == 0 ? base - 1 : base;
}

const int BASE = gen();
const int MAXN = 1e5 + 5;

ull pw[MAXN], ipw[MAXN];

struct SegmentTree {
    struct Node {
        ull open, close, delLeft, delRight;
        int cntOpen, cntClose;
        bool fail;
        const Node *left, *right;

        pair<ull, ull> splitOpen(int k) const {
            if (k == 0)
                return {0, open};
            if (k == cntOpen)
                return {open, 0};
            int cntLeft = cntOpen - right->cntOpen, del = min(left->cntOpen, right->cntClose);
            if (k <= cntLeft) {
                auto pi = left->splitOpen(k);
                return {pi.first, add(mul(mul(sub(pi.second, delLeft), ipw[del]), pw[right->cntOpen]), right->open)};
            } else {
                auto pi = right->splitOpen(k - cntLeft);
                return {add(mul(mul(sub(left->open, delLeft), ipw[del]), pw[k - cntLeft]), pi.first), pi.second};
            }
        }

        pair<ull, ull> splitClose(int k) const {
            if (k == 0)
                return {0, close};
            if (k == cntClose)
                return {close, 0};
            int del = min(left->cntOpen, right->cntClose);
            if (k <= left->cntClose) {
                auto pi = left->splitClose(k);
                return {pi.first, add(mul(mul(sub(right->close, delRight), ipw[del]), pw[left->cntClose - k]), pi.second)};
            } else {
                auto pi = right->splitClose(k - left->cntClose + del);
                return {add(mul(mul(sub(pi.first, delRight), ipw[del]), pw[left->cntClose]), left->close), pi.second};
            }
        }

        void leaf(int val) {
            if (val > 0) {
                open = val;
                cntOpen = 1;
                close = delLeft = delRight = cntClose = fail = left = right = 0;
            } else {
                close = -val;
                cntClose = 1;
                open = delLeft = delRight = cntOpen = fail = left = right = 0;
            }
        }

        void pull(const Node *a, const Node *b) {
            cntOpen = a->cntOpen + b->cntOpen - min(a->cntOpen, b->cntClose);
            cntClose = a->cntClose + b->cntClose - min(a->cntOpen, b->cntClose);
            fail = a->fail || b->fail;
            left = a;
            right = b;
            if (!fail) {
                if (a->cntOpen > b->cntClose) {
                    // match some suffix of open brackets on left with close brackets on right
                    auto pi = a->splitOpen(a->cntOpen - b->cntClose);
                    if (pi.second == b->close) {
                        open = add(mul(pi.first, pw[b->cntOpen]), b->open);
                        close = a->close;
                        delLeft = pi.second;
                        delRight = b->close;
                    } else {
                        fail = true;
                    }
                } else {
                    // match some prefix of close brackets on right with open brackets on left
                    auto pi = b->splitClose(a->cntOpen);
                    if (pi.first == a->open) {
                        open = b->open;
                        close = add(mul(pi.second, pw[a->cntClose]), a->close);
                        delLeft = a->open;
                        delRight = pi.first;
                    } else {
                        fail = true;
                    }
                }
            }
        }
    };

    int n, ptr;
    vector<int> a;
    vector<Node> st, extra;

    SegmentTree(int _n) : n(_n), ptr(0), a(n), st(4*n), extra(n) {
        build(1, 0, n-1);
    }

    SegmentTree(const vector<int> &_a) : n((int) _a.size()), ptr(0), a(_a), st(4*n), extra(n) {
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
        st[p].pull(&st[2*p], &st[2*p+1]);
    }

    const Node* query(int p, int l, int r, int i, int j) {
        if (l == i && r == j)
            return &st[p];
        int m = (l + r) / 2;
        if (j <= m)
            return query(2*p, l, m, i, j);
        else if (i > m)
            return query(2*p+1, m+1, r, i, j);
        const Node *ls = query(2*p, l, m, i, m), *rs = query(2*p+1, m+1, r, m+1, j);
        Node &ret = extra[ptr++];
        if (ptr == n)
            ptr = 0;
        ret.pull(ls, rs);
        return &ret;
    }

    bool query(int i, int j) {
        const Node *ret = query(1, 0, n-1, i, j);
        return !ret->fail && ret->cntOpen == 0 && ret->cntClose == 0;
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
        st[p].pull(&st[2*p], &st[2*p+1]);
    }

    void update(int idx, int val) {
        update(1, 0, n-1, idx, val);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    vector<int> s(n);
    for (int i=0; i<n; i++)
        cin >> s[i];
    int q;
    cin >> q;

    ull inv = inverse(BASE);
    pw[0] = ipw[0] = 1;
    for (int i=1; i<=n; i++) {
        pw[i] = mul(pw[i-1], BASE);
        ipw[i] = mul(ipw[i-1], inv);
    }

    SegmentTree st(s);
    for (int i=0; i<q; i++) {
        int t, x, y;
        cin >> t >> x >> y;
        if (t == 1) {
            x--;
            st.update(x, y);
        } else {
            x--, y--;
            cout << (st.query(x, y) ? "Yes" : "No") << "\n";
        }
    }

    return 0;
}