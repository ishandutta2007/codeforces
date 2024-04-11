#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define pbc push_back
#define pob pop_back()
#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define vin(a) for (auto& i : a) cin >> i

// mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

template<typename T1, typename T2> 
inline void chkmin(T1& x, const T2& y) {
    if (y < x) x = y;
}

template<typename T1, typename T2>
inline void chkmax(T1& x, const T2& y) {
    if (x < y) x = y;
}

struct Edge{
    int u, v;
};

struct Query{
    int l, r = INT_MAX, id;
    Query() = default;
    bool operator<(const Query& other) const {
        return tie(r, l, id) < tie(other.r, l, id);
    }
};

struct SegmentTree{
    int n;
    vector<Query> tree;
    vector<Query> queries;
    SegmentTree() {}

    void build(int v, int tl, int tr) {
        if (tl >= tr) {
            return;
        } else if (tl == tr - 1) {
            tree[v] = queries[tl];
        } else {
            int tm = (tl + tr) / 2;
            build(v * 2, tl, tm);
            build(v * 2 + 1, tm, tr);
            tree[v] = min(tree[v * 2], tree[v * 2 + 1]);
        }
    }

    SegmentTree(const vector<Query>& queries_) 
        : n(queries_.size())
        , tree(n * 4)
        , queries(queries_) {
        sort(all(queries), [&] (const Query& lhs, const Query& rhs) {
            return lhs.l < rhs.l;
        });
        build(1, 0, n);
    }

    Query getBest(int v, int tl, int tr, int l, int r, int need) {
        if (tree[v].r > need) {
            return Query();
        }
        if (tl >= r || tr <= l) {
            return Query(); 
        } else if (tl == tr - 1) {
            tree[v] = Query();
            return queries[tl];
        } else {
            int tm = (tl + tr) / 2;
            Query ans = getBest(v * 2, tl, tm, l, r, need);
            if (ans.r > need) {
                ans = getBest(v * 2 + 1, tm, tr, l, r, need);
            }
            tree[v] = min(tree[v * 2], tree[v * 2 + 1]);
            return ans;
        }
    }

    Query getBest(int l, int r, int need) {
        int L, R;
        L = -1, R = n;
        while (L < R - 1) {
            int M = (L + R) / 2;
            if (queries[M].l < l) {
                L = M;
            } else {
                R = M;
            }
        }
        l = R;
        L = -1, R = n;
        while (L < R - 1) {
            int M = (L + R) / 2;
            if (queries[M].l < r) {
                L = M;
            } else {
                R = M;
            }
        }
        r = L;
        // cerr << "l = " << l << " r = " << r << endl;
        if (l > r) {
            return Query();
        }
        return getBest(1, 0, n, l, r + 1, need);
    }
};

struct Dsu{
    vector<int> par;
    vector<set<pair<int, int>>> data;     
    Dsu() = default;
    Dsu(int n) : par(n), data(n) {
        iota(all(par), 0);
        for (int i = 0; i < n; ++i) {
            data[i].insert({i, i});
        }
    }
    int getPar(int v) {
        if (v == par[v]) {
            return v;
        } else {
            return par[v] = getPar(par[v]);
        }
    }
    vector<pair<int, int>> uni(int a, int b) {
        a = getPar(a);
        b = getPar(b);
        if (a == b) {
            return {};
        }
        if (data[a].size() > data[b].size()) {
            swap(a, b);
        }
        vector<pair<int, int>> ans;
        for (auto [l, r] : data[a]) {
            auto itR = data[b].lower_bound(mp(r, -1));
            auto itL = data[b].lower_bound(mp(l, -1));
            bool okR = false, okL = false;
            if (itR != data[b].end() && itR->first == r + 1) {
                okR = true;
            }
            if (itL != data[b].begin()) {
                auto previtL = itL;
                --previtL;
                if (previtL->second == l - 1) {
                    okL = true;
                }
            }
            pair<int, int> newSegment;
            if (okL && okR) {
                --itL;
                newSegment = {itL->first, itR->second};
                data[b].erase(itL);
                data[b].erase(itR);
            } else if (okL) {
                --itL;
                newSegment = {itL->first, r};
                data[b].erase(itL);
            } else if (okR) {
                newSegment = {l, itR->second};
                data[b].erase(itR);
            } else {
                newSegment = {l, r};
            }
            data[b].insert(newSegment);
            if (okL || okR) {
                ans.push_back(newSegment);
            }
        } 
        par[a] = b;
        return ans;
    }
};

const int N = 2e5 + 10;
int n, m;
Edge edges[N];
int q;
vector<Query> queries;
vector<int> ans;
    
void solve() {
    cin >> n >> m >> q;
    for (int i = 0; i < m; ++i) {
        cin >> edges[i].u >> edges[i].v;
        --edges[i].u;
        --edges[i].v;
    }

    queries.resize(q);
    ans.assign(q, m + 1);
    for (int i = 0; i < q; ++i) {
        cin >> queries[i].l >> queries[i].r;
        queries[i].l--;
        queries[i].r--;
        queries[i].id = i;
        if (queries[i].l == queries[i].r) {
            ans[i] = 0;
        }
    }
    SegmentTree st(queries);
    Dsu dsu(n);

    for (int i = 0; i < m; ++i) {
        auto fans = dsu.uni(edges[i].u, edges[i].v);
        for (auto [l, r] : fans) {
            // cerr << "l = " << l << " r = " << r << endl;
            Query query;
            while ((query = st.getBest(l, r, r)).r <= r) {
                // cerr << query.id << endl;
                chkmin(ans[query.id], i + 1);
            }
        }
    }

    for (int i = 0; i < q; ++i) {
        if (i > 0) {
            cout << ' ';
        }
        cout << ans[i];
    }
    cout << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}