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

struct Query{
    int x, l, r, id, type;
    bool operator<(const Query& other) const {
        return x < other.x;
    }
};

struct Line{
    ll k = 0, b = 0;
    Line() = default;
    Line(ll _k, ll _b) : k(_k), b(_b) {} 
    ll eval(ll x) const {
        return k * x + b;
    }
};

struct Event{
    int x, l, r;
    Line val;
    bool operator<(const Event& other) const {
        return x < other.x;
    }
};

Line merge(const Line& lhs, const Line& rhs) {
    return Line(lhs.k + rhs.k, lhs.b + rhs.b);
}

struct SegmentTree{
    int n;
    vector<Line> tree;
    vector<Line> mod;
    SegmentTree(int _n) : n(_n), tree(4 * n), mod(4 * n) {}
    void push(int v) {
        mod[v * 2] = merge(mod[v], mod[v * 2]);
        mod[v * 2 + 1] = merge(mod[v], mod[v * 2 + 1]);
        mod[v] = Line();
    }
    Line getVal(int v, int sz) {
        return merge(Line(mod[v].k * sz, mod[v].b * sz), tree[v]);
    }
    void upd(int v, int tl, int tr, int l, int r, Line val) {
        if (tl >= r || tr <= l) return;
        if (tl >= l && tr <= r) {
            mod[v] = merge(mod[v], val);
        } else {
            int tm = (tl + tr) / 2;
            push(v);
            upd(v * 2, tl, tm, l, r, val);
            upd(v * 2 + 1, tm, tr, l, r, val);
            tree[v] = merge(getVal(v * 2, tm - tl), getVal(v * 2 + 1, tr - tm));
        }
    }
    void upd(int l, int r, Line val) {
        upd(1, 0, n, l, r + 1, val);
    }
    Line get(int v, int tl, int tr, int l, int r) {
        if (tl >= r || tr <= l) return Line();
        if (tl >= l && tr <= r) return getVal(v, tr - tl);
        push(v);
        int tm = (tl + tr) / 2;
        Line ans = merge(
            get(v * 2, tl, tm, l, r),
            get(v * 2 + 1, tm, tr, l, r)
            );
        tree[v] = merge(getVal(v * 2, tm - tl), getVal(v * 2 + 1, tr - tm));
        return ans;
    }
    Line get(int l, int r) {
        return get(1, 0, n, l, r + 1);
    }
};

const int N = 2e5 + 10;
int n, q;
int p[N];
int rp[N];
vector<Query> queries;
vector<Event> events;
vector<ll> ans;
vector<pair<int, int>> segments[N];
int L[N], R[N];

void addEvent(int min_l, int max_l, int min_r, int max_r) {
    events.push_back({min_l, min_r, max_r, Line(1, -min_l + 1)});
    events.push_back({max_l + 1, min_r, max_r, Line(-1, +min_l - 1 + max_l - min_l + 1)});
}

void buildEvents() {
    for (int i = 0; i < n; ++i) {
        rp[p[i]] = i;
    }

    vector<int> st;
    for (int i = 0; i < n; ++i) {
        while (!st.empty() && p[st.back()] < p[i]) st.pop_back();
        if (st.empty()) {
            L[i] = 0;
        } else {
            L[i] = st.back() + 1;
        }
        st.push_back(i);
    }
    st.clear();
    for (int i = n - 1; i >= 0; --i) {
        while (!st.empty() && p[st.back()] < p[i]) st.pop_back();
        if (st.empty()) {
            R[i] = n - 1;
        } else {
            R[i] = st.back() - 1;
        }
        st.push_back(i);
    }

    for (int a = 1; a <= n; ++a) {
        for (int b = a + 1; (ll)a * b <= n; ++b) {
            int l = rp[a - 1];
            int r = rp[b - 1];
            int pos = rp[a * b - 1];
            if (l > r) swap(l, r);
            chkmin(l, pos);
            chkmax(r, pos);
            if (L[pos] > l || r > R[pos]) continue;
            segments[pos].push_back({l, r});
        }
    }
    for (int pos = 0; pos < n; ++pos) {
        sort(all(segments[pos]));
        vector<pair<int, int>> hull;
        for (auto [l, r] : segments[pos]) {
            while (!hull.empty() && hull.back().second >= r) {
                hull.pop_back();
            }
            hull.push_back({l, r});
        }
        int min_l = L[pos];
        int max_r = R[pos];
        for (auto [l, r] : hull) {
            addEvent(min_l, l, r, max_r);
            min_l = l + 1;
        }
    }
}

void process() {
    sort(all(events));
    sort(all(queries));
    SegmentTree st(n);
    int pos = 0;
    for (auto [x, l, r, id, type] : queries) {
        while (pos < (int)events.size() && events[pos].x <= x) {
            st.upd(events[pos].l, events[pos].r, events[pos].val);
            ++pos;
        }
        ans[id] += (ll)type * st.get(l, r).eval(x);
    }
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        --p[i];
    }
    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        --l;
        --r;
        queries.push_back({l - 1, l, r, i, -1});
        queries.push_back({r, l, r, i, 1});
    }
    ans.resize(q);
    buildEvents();
    process();
    for (int i = 0; i < q; ++i) {
        cout << ans[i] << '\n';
    }
    return 0;
}