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

struct PermutationTree {
    struct SegmentTree {
        int n;
        vector<int> ans, lazy;

        SegmentTree(int _n) : n(_n), ans(4 * n), lazy(4 * n) {}

        void push(int p, bool leaf) {
            if (lazy[p]) {
                ans[p] += lazy[p];
                if (!leaf) {
                    lazy[2*p] += lazy[p];
                    lazy[2*p+1] += lazy[p];
                }
                lazy[p] = 0;
            }
        }

        int query(int p, int l, int r, int i, int j) {
            push(p, l == r);
            if (i > r || j < l)
                return INT_MAX;
            if (i <= l && r <= j)
                return ans[p];
            int m = (l + r) / 2;
            return min(query(2 * p, l, m, i, j), query(2 * p + 1, m + 1, r, i, j));
        }

        void update(int p, int l, int r, int i, int j, int v) {
            push(p, l == r);
            if (i > r || j < l)
                return;
            if (i <= l && r <= j) {
                lazy[p] += v;
                push(p, l == r);
                return;
            }
            int m = (l + r) / 2;
            update(2 * p, l, m, i, j, v);
            update(2 * p + 1, m + 1, r, i, j, v);
            ans[p] = min(ans[2*p], ans[2*p+1]);
        }

        int query(int l, int r) {
            return query(1, 0, n - 1, l, r);
        }

        void update(int l, int r, int v) {
            update(1, 0, n - 1, l, r, v);
        }
    };

    vector<int> a, stk, mnStk, mxStk, type;
    vector<pair<int, int>> range, span;
    vector<vector<int>> adj;
    SegmentTree st;

    PermutationTree(int n) : mnStk({-1}), mxStk({-1}), type(n), range(n), span(n), adj(n), st(n) {
        a.reserve(n);
    }

    PermutationTree(const vector<int> &p) : PermutationTree((int) p.size()) {
        for (int x : p)
            extend(x);
    }

    bool adjacent(int i, int j) {
        return range[i].second + 1 == range[j].first;
    }

    pair<int, int> getRange(const pair<int, int> &p, const pair<int, int> &q) {
        return {min(p.first, q.first), max(p.second, q.second)};
    }

    void extend(int x) {
        int i = (int) a.size();
        a.push_back(x);
        while (mnStk.back() != -1 && x < a[mnStk.back()]) {
            int j = mnStk.back();
            mnStk.pop_back();
            st.update(mnStk.back() + 1, j, a[j] - x);
        }
        mnStk.push_back(i);
        while (mxStk.back() != -1 && x > a[mxStk.back()]) {
            int j = mxStk.back();
            mxStk.pop_back();
            st.update(mxStk.back() + 1, j, x - a[j]);
        }
        mxStk.push_back(i);
        range[i] = {x, x};
        span[i] = {i, i};
        int u = i;
        while (!stk.empty()) {
            if (adjacent(stk.back(), u) || adjacent(u, stk.back())) {
                if ((adjacent(stk.back(), u) && type[stk.back()] == 1) || (adjacent(u, stk.back()) && type[stk.back()] == 2)) {
                    range[stk.back()] = getRange(range[stk.back()], range[u]);
                    span[stk.back()] = getRange(span[stk.back()], span[u]);
                    adj[stk.back()].push_back(u);
                    u = stk.back();
                } else {
                    type.push_back(adjacent(stk.back(), u) ? 1 : 2);
                    range.push_back(getRange(range[stk.back()], range[u]));
                    span.push_back(getRange(span[stk.back()], span[u]));
                    adj.push_back({stk.back(), u});
                    u = (int) type.size() - 1;
                }
                stk.pop_back();
            } else if (span[u].first > 0 && st.query(0, span[u].first - 1) == 0) {
                type.push_back(0);
                range.push_back(range[u]);
                span.push_back(span[u]);
                adj.push_back({u});
                u = (int) type.size() - 1;
                do {
                    range[u] = getRange(range[u], range[stk.back()]);
                    span[u] = getRange(span[u], span[stk.back()]);
                    adj[u].push_back(stk.back());
                    stk.pop_back();
                } while (range[u].second - range[u].first != span[u].second - span[u].first);
                reverse(adj[u].begin(), adj[u].end());
            } else {
                break;
            }
        }
        stk.push_back(u);
        st.update(0, i, -1);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> p(n);
    for (int i=0; i<n; i++) {
        int r, c;
        cin >> r >> c;
        p[--r] = c;
    }

    PermutationTree pt(p);
    long long ret = 0;
    for (int i=0; i<(int)pt.adj.size(); i++)
        ret += pt.type[i] == 0 ? 1 : (long long) pt.adj[i].size() * (pt.adj[i].size() - 1) / 2;
    cout << ret << "\n";

    return 0;
}