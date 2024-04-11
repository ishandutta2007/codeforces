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

const int MAX = 1e5 + 5;
const int LOG = 20;
const int NODES = 4 * MAX * LOG;
const int ALL = (1 << LOG) - 1;

int id = 1, st[NODES], pl[NODES], pr[NODES], lazy[NODES], has[NODES][2];

void apply(int p, int i, int x) {
    if (i != -1 && x >> i & 1)
        swap(pl[p], pr[p]);
    lazy[p] ^= x;
    int change = (has[p][0] ^ has[p][1]) & x;
    has[p][0] ^= change;
    has[p][1] ^= change;
}

void push(int p, int i) {
    if (lazy[p]) {
        if (pl[p]) apply(pl[p], i - 1, lazy[p]);
        if (pr[p]) apply(pr[p], i - 1, lazy[p]);
        lazy[p] = 0;
    }
}

void pull(int p) {
    st[p] = st[pl[p]] + st[pr[p]];
    has[p][0] = has[pl[p]][0] | has[pr[p]][0];
    has[p][1] = has[pl[p]][1] | has[pr[p]][1];
}

int ins(int p, int l, int r, int i) {
    if (!p)
        p = id++;
    if (l == r) {
        st[p] = 1;
        has[p][0] = i ^ ALL;
        has[p][1] = i;
        return p;
    }
    int m = (l + r) / 2;
    if (i <= m)
        pl[p] = ins(pl[p], l, m, i);
    else
        pr[p] = ins(pr[p], m + 1, r, i);
    pull(p);
    return p;
}

pair<int, int> query(int p, int l, int r, int i, int j) {
    if (i > r || j < l)
        return {p, 0};
    if (i <= l && r <= j)
        return {0, p};
    push(p, __lg(r - l + 1) - 1);
    int m = (l + r) / 2, q = id++;
    tie(pl[p], pl[q]) = query(pl[p], l, m, i, j);
    tie(pr[p], pr[q]) = query(pr[p], m + 1, r, i, j);
    pull(p);
    pull(q);
    return {p, q};
}

int merge(int p, int q, int i) {
    if (!p || !q)
        return p ^ q;
    if (i == -1)
        return p;
    push(p, i);
    push(q, i);
    pl[p] = merge(pl[p], pl[q], i - 1);
    pr[p] = merge(pr[p], pr[q], i - 1);
    pull(p);
    return p;
}

int applyOR(int p, int i, int x) {
    if (!p)
        return 0;
    if (!(x & has[p][0] & has[p][1])) {
        apply(p, i, x & has[p][0]);
        return p;
    }
    push(p, i);
    if (x >> i & 1) {
        pr[p] = applyOR(merge(pl[p], pr[p], i - 1), i - 1, x);
        pl[p] = 0;
    } else {
        pl[p] = applyOR(pl[p], i - 1, x);
        pr[p] = applyOR(pr[p], i - 1, x);
    }
    pull(p);
    return p;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;
    int rt = 0;
    for (int i=0; i<n; i++) {
        int a;
        cin >> a;
        rt = ins(rt, 0, ALL, a);
    }

    for (int i=0; i<q; i++) {
        int t, l, r;
        cin >> t >> l >> r;

        int cur;
        tie(rt, cur) = query(rt, 0, ALL, l, r);
        if (t == 4) {
            cout << st[cur] << "\n";
        } else {
            int x;
            cin >> x;
            if (t == 1) {
                apply(cur, LOG - 1, ALL);
                cur = applyOR(cur, LOG - 1, x ^ ALL);
                apply(cur, LOG - 1, ALL);
            } else if (t == 2) {
                cur = applyOR(cur, LOG - 1, x);
            } else {
                apply(cur, LOG - 1, x);
            }
        }
        rt = merge(rt, cur, LOG - 1);
    }

    return 0;
}