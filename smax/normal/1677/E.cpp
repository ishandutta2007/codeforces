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

struct SegmentTree {
    struct Node {
        int l, r;
        long long sumA, sumB, timestamp, lazysum, cumsum, lazyTimestamp;
        bool lazy;

        void leaf(int val) {
            sumA = val;
            sumB = timestamp = lazysum = cumsum = lazyTimestamp = lazy = 0;
        }

        void pull(const Node &a, const Node &b) {
            sumA = a.sumA + b.sumA;
            timestamp = max(a.timestamp, b.timestamp);
            sumB = a.sumB + b.sumB + a.sumA * (timestamp - a.timestamp) + b.sumA * (timestamp - b.timestamp);
        }

        void push(const Node &other) {
            if (lazy) {
                cumsum += lazysum * (other.lazyTimestamp - lazyTimestamp) + other.cumsum;
                lazysum += other.lazysum;
            } else {
                cumsum = other.cumsum;
                lazysum = other.lazysum;
                lazy = true;
            }
            lazyTimestamp = other.lazyTimestamp;
        }

        void apply() {
            sumB += sumA * (lazyTimestamp - timestamp) + (r - l + 1) * cumsum;
            sumA += (r - l + 1) * lazysum;
            timestamp = lazyTimestamp;
            lazysum = cumsum = lazyTimestamp = lazy = 0;
        }
    };

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
        if (st[p].lazy) {
            if (st[p].l != st[p].r) {
                st[2*p].push(st[p]);
                st[2*p+1].push(st[p]);
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

    long long query(int i, int j, long long ti) {
        Node ret = query(1, i, j);
        return ret.sumB + (ti - ret.timestamp) * ret.sumA;
    }

    void update(int p, int i, int j, int val, int ti) {
        if (st[p].l == i && st[p].r == j) {
            Node other;
            other.lazy = true;
            other.lazysum = val;
            other.cumsum = 0;
            other.lazyTimestamp = ti;
            st[p].push(other);
            push(p);
            return;
        }
        push(p);
        int m = (st[p].l + st[p].r) / 2;
        if (j <= m) {
            update(2*p, i, j, val, ti);
            push(2*p+1);
        } else if (i > m) {
            push(2*p);
            update(2*p+1, i, j, val, ti);
        } else {
            update(2*p, i, m, val, ti);
            update(2*p+1, m+1, j, val, ti);
        }
        st[p].pull(st[2*p], st[2*p+1]);
    }

    void update(int i, int j, int val, int ti) {
        update(1, i, j, val, ti);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;
    vector<int> p(n);
    for (int &x : p)
        cin >> x;
    vector<vector<pair<int, int>>> queries(n);
    for (int i=0; i<q; i++) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        queries[r].emplace_back(l, i);
    }

    vector<int> pos(n + 1);
    for (int i=0; i<n; i++)
        pos[p[i]] = i;

    vector<int> stk, ri(n);
    for (int i=n-1; i>=0; i--) {
        while (!stk.empty() && p[stk.back()] < p[i])
            stk.pop_back();
        ri[i] = stk.empty() ? n : stk.back();
        stk.push_back(i);
    }

    stk.clear();
    vector<pair<int, int>> zui(n, {-1, -1});
    vector<vector<array<int, 3>>> pending(n);
    vector<long long> ret(q);
    SegmentTree st(n);
    for (int i=0; i<n; i++) {
        DEBUG("process", i);
        DEBUG("tot", st.query(0, i, (long long) i));
        while (!stk.empty() && p[stk.back()] < p[i]) {
            int j = stk.back();
            stk.pop_back();
            if (zui[j].first != -1) {
                DEBUG("rem", zui[j].first, zui[j].second, j, p[j]);
                st.update(zui[j].first, zui[j].second, -1, i);
            }
        }
        int k = stk.empty() ? -1 : stk.back();
        stk.push_back(i);
        for (int j=1; j*j<=p[i]; j++)
            if (p[i] % j == 0 && j != p[i] / j) {
                int l = min(pos[j], pos[p[i]/j]), r = max(pos[j], pos[p[i]/j]);
                if (k < l && r < ri[i]) {
                    pending[max(r, i)].push_back({k + 1, min(l, i), i});
                    DEBUG(l, r, i, p[i]);
                }
            }
        for (auto [ka, l, j] : pending[i])
            if (i < ri[j]) {
                if (zui[j].first != -1) {
                    DEBUG("rem", zui[j].first, zui[j].second, j, p[j]);
                    st.update(zui[j].first, zui[j].second, -1, i);
                    l = max(l, zui[j].second);
                }
                DEBUG("ins", ka, l, j, p[j]);
                st.update(ka, l, 1, i);
                zui[j] = {ka, l};
            }
        for (auto [l, j] : queries[i]) {
            DEBUG("query", l, i, st.query(l, i, i + 1LL));
            ret[j] = st.query(l, i, i + 1LL);
        }
    }

    for (long long x : ret)
        cout << x << "\n";

    return 0;
}