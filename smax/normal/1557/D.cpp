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

// // Source: https://github.com/kth-competitive-programming/kactl/blob/main/content/various/BumpAllocator.h

// static char buf[450 << 20];
// void* operator new(size_t s) {
// 	static size_t i = sizeof buf;
// 	assert(s < i);
// 	return (void*)&buf[i -= s];
// }
// void operator delete(void*) {}

const int INF = 1e9;

// struct Node {
//     pair<int, int> lazy;
//     pair<pair<int, int>, int> ans;
//     bool flag;
//     Node *l, *r;

//     Node(int i) : ans({INF, INF}, i), flag(false), l(NULL), r(NULL) {}
// };

// void push(Node *p, int l, int r) {
//     if (p && p->flag) {
//         p->ans.first = min(p->ans.first, p->lazy);
//         p->flag = false;
//         if (l != r) {
//             int m = (l + r) / 2;
//             if (!p->l) p->l = new Node(l);
//             p->l->lazy = min(p->l->lazy, p->lazy);
//             p->l->flag = true;
//             if (!p->r) p->r = new Node(m+1);
//             p->r->lazy = min(p->r->lazy, p->lazy);
//             p->r->flag = true;
//         }
//     }
// }

// pair<pair<int, int>, int> query(Node *p, int l, int r, int i, int j) {
//     push(p, l, r);
//     if (i > r || j < l || !p)
//         return {{INF, INF}, INF};
//     if (i <= l && r <= j)
//         return p->ans;
//     int m = (l + r) / 2;
//     return min(query(p->l, l, m, i, j), query(p->r, m+1, r, i, j));
// }

// void update(Node *p, int l, int r, int i, int j, int v, int t) {
//     push(p, l, r);
//     if (i > r || j < l || !p)
//         return;
//     if (i <= l && r <= j) {
//         p->lazy = {v, t};
//         p->flag = true;
//         push(p, l, r);
//         return;
//     }
//     int m = (l + r) / 2;
//     if (!p->l) p->l = new Node(l);
//     update(p->l, l, m, i, j, v, t);
//     if (!p->r) p->r = new Node(m+1);
//     update(p->r, m+1, r, i, j, v, t);
//     p->ans = min(p->l->ans, p->r->ans);
// }

struct Node {
    int l, r;
    pair<int, int> lazy;
    pair<pair<int, int>, int> ans;
    bool flag = false;

    void leaf(int val) {
        ans = {{INF, INF}, l};
    }

    void pull(const Node &a, const Node &b) {
        ans = min(a.ans, b.ans);
    }

    void push(const pair<int, int> &p) {
        lazy = p;
        flag = true;
    }

    void apply() {
        ans.first = min(ans.first, lazy);
        flag = false;
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
        if (st[p].flag) {
            if (st[p].l != st[p].r) {
                st[2*p].push(st[p].lazy);
                st[2*p+1].push(st[p].lazy);
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

    pair<pair<int, int>, int> query(int i, int j) {
        return query(1, i, j).ans;
    }

    void update(int p, int i, int j, int v, int t) {
        if (st[p].l == i && st[p].r == j) {
            st[p].push({v, t});
            push(p);
            return;
        }
        push(p);
        int m = (st[p].l + st[p].r) / 2;
        if (j <= m) {
            update(2*p, i, j, v, t);
            push(2*p+1);
        } else if (i > m) {
            push(2*p);
            update(2*p+1, i, j, v, t);
        } else {
            update(2*p, i, m, v, t);
            update(2*p+1, m+1, j, v, t);
        }
        st[p].pull(st[2*p], st[2*p+1]);
    }

    void update(int i, int j, int v, int t) {
        update(1, i, j, v, t);
    }
};

pair<pair<int, int>, int> comb(const pair<pair<int, int>, int> &a, int b) {
    return {{a.first.first + b, a.first.second}, a.second};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> intervals(n);
    vector<int> compress;
    while (m--) {
        int i, l, r;
        cin >> i >> l >> r;
        i--;
        intervals[i].emplace_back(l, r);
        compress.push_back(l);
        compress.push_back(r);
    }

    sort(compress.begin(), compress.end());
    compress.erase(unique(compress.begin(), compress.end()), compress.end());
    m = (int) compress.size();

    auto getPos = [&] (int i) -> int {
        return int(lower_bound(compress.begin(), compress.end(), i) - compress.begin());
    };

    SegmentTree st(m);
    int delta = 0;
    st.update(0, m - 1, 0, -1);
    vector<vector<array<int, 4>>> nintervals;
    for (int i=0; i<n; i++) {
        sort(intervals[i].begin(), intervals[i].end());
        vector<pair<int, int>> nv;
        int curL = -1, curR = -1;
        for (auto [l, r] : intervals[i]) {
            l = getPos(l);
            r = getPos(r);
            if (l > curR) {
                if (curR != -1)
                    nv.emplace_back(curL, curR);
                curL = l;
                curR = r;
            }
            curR = max(curR, r);
        }
        if (curR != -1)
            nv.emplace_back(curL, curR);

        pair<pair<int, int>, int> dp({INF, INF}, INF);
        DEBUG(nv);
        for (auto [l, r] : nv)
            dp = min(dp, comb(st.query(l, r), delta));
        delta++;
        nintervals.emplace_back();
        for (auto [l, r] : nv) {
            st.update(l, r, dp.first.first - delta, i);
            nintervals.back().push_back({l, r, dp.first.second, dp.second});
        }
    }

    auto ret = st.query(0, m - 1);
    int last = n;
    cout << ret.first.first + delta << "\n";
    while (true) {
        for (int i=ret.first.second+1; i<last; i++)
            cout << i + 1 << " ";
        last = ret.first.second;
        if (ret.first.second == -1)
            break;
        for (auto [l, r, x, y] : nintervals[ret.first.second])
            if (l <= ret.second && ret.second <= r) {
                ret.first.second = x;
                ret.second = y;
                break;
            }
    }
    cout << "\n";

    return 0;
}