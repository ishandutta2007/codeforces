//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
template <class T>
using V = vector<T>;
template <class T>
using VV = V<V<T>>;

template <class T>
V<T> make_vec(size_t a) {
    return V<T>(a);
}

template <class T, class... Ts>
auto make_vec(size_t a, Ts... ts) {
    return V<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i, n) rep2(i, 0, n)
#define rep2(i, m, n) for (int i = m; i < (n); i++)
#define per(i, b) per2(i, 0, b)
#define per2(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
#define ALL(c) (c).begin(), (c).end()
#define SZ(x) ((int)(x).size())

constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }

template <class T, class U>
void chmin(T& t, const U& u) {
    if (t > u) t = u;
}
template <class T, class U>
void chmax(T& t, const U& u) {
    if (t < u) t = u;
}

template <class T>
void mkuni(vector<T>& v) {
    sort(ALL(v));
    v.erase(unique(ALL(v)), end(v));
}

template <class T>
vector<int> sort_by(const vector<T>& v) {
    vector<int> res(v.size());
    iota(res.begin(), res.end(), 0);
    sort(res.begin(), res.end(), [&](int i, int j) { return v[i] < v[j]; });
    return res;
}

template <class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
    os << "(" << p.first << "," << p.second << ")";
    return os;
}

template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    os << "{";
    rep(i, v.size()) {
        if (i) os << ",";
        os << v[i];
    }
    os << "}";
    return os;
}

#ifdef LOCAL
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << H;
    debug_out(T...);
}
#define debug(...) \
    cerr << __LINE__ << " [" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define dump(x) cerr << __LINE__ << " " << #x << " = " << (x) << endl
#else
#define debug(...) (void(0))
#define dump(x) (void(0))
#endif

template <class T>
void scan(vector<T>& v, T offset = T(0)) {
    for (auto& x : v) {
        cin >> x;
        x += offset;
    }
}

template <class T>
void print(T x, int suc = 1) {
    cout << x;
    if (suc == 1)
        cout << "\n";
    else if (suc == 2)
        cout << " ";
}

template <class T>
void print(const vector<T>& v, int suc = 1) {
    for (int i = 0; i < v.size(); ++i)
        print(v[i], i == int(v.size()) - 1 ? suc : 2);
}

struct prepare_io {
    prepare_io() {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(10);
    }
} prep_io;
/*
// i2g[i] :=  i 
// g2i[g] :=  g 

vector<int> i2g;
V<int> rem;
vector<vector<int>> g2i;

void init(int n) {
    i2g.resize(n);
    g2i.resize(n);
    rem.resize(n);
    for (int i = 0; i < n; ++i) {
        i2g[i] = i;
        g2i[i].assign(1, i);
    }
}

void merge(int ia, int ib) {
    if (g2i[i2g[ia]].size() < g2i[i2g[ib]].size()) {
        swap(ia, ib);
    }

    int ga = i2g[ia], gb = i2g[ib];
    for (int j : g2i[gb]) i2g[j] = ga;
    g2i[ga].insert(g2i[ga].end(), g2i[gb].begin(), g2i[gb].end());
    rem[ga] += rem[gb];
    g2i[gb].clear();
}

bool is_same_group(int ia, int ib) { return i2g[ia] == i2g[ib]; }
*/
class unionfind {
    vector<int> par, size;

   public:
    void init(int n) {
        par.resize(n);
        size.resize(n);

        for (int i = 0; i < n; i++) {
            par[i] = i;
            size[i] = 1;
        }
    }

    int find(int x) {
        if (par[x] == x)
            return x;
        else
            return par[x] = find(par[x]);
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return;
        if (size[x] < size[y]) swap(x, y);

        par[y] = x;
        size[x] += size[y];
    }

    bool same(int x, int y) { return (find(x) == find(y)); }
    int get_size(int x) { return size[find(x)]; }
};

int main() {
    int n, d;
    cin >> n >> d;
    // init(n);
    unionfind uf;
    uf.init(n);

    int mx = 1;
    int zan = 0;

    multiset<int> st;
    rep(i, n) st.insert(1);

    rep(i, d) {
        int x, y;
        cin >> x >> y;
        --x, --y;

        if (uf.same(x, y)) {
            // rem[i2g[x]]++;
            zan++;
        } else {
            int cx = uf.get_size(x);
            int cy = uf.get_size(y);
            {
                auto it = st.find(cx);
                st.erase(it);
            }
            {
                auto it = st.find(cy);
                st.erase(it);
            }

            uf.unite(x, y);
            st.insert(uf.get_size(x));
        }

        auto it = --st.end();
        int ans = *it - 1;
        rep(j, zan) {
            if (it == st.begin()) break;
            it--;
            ans += *it;
        }

        print(ans);
    }

    return 0;
}