#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
template <class T>
using V = vector<T>;
template <class T>
using VV = V<V<T>>;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i, n) rep2(i, 0, n)
#define rep2(i, m, n) for (int i = m; i < (n); i++)
#define ALL(c) (c).begin(), (c).end()

constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }

template <class T, class U>
void chmin(T& t, const U& u) {
    if (t > u) t = u;
}
template <class T, class U>
void chmax(T& t, const U& u) {
    if (t < u) t = u;
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

class unionfind {
    vector<int> par, rank;

   public:
    void init(int n) {
        par.resize(n);
        rank.resize(n);

        for (int i = 0; i < n; i++) {
            par[i] = i;
            rank[i] = 0;
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

        if (rank[x] < rank[y])
            par[x] = y;
        else {
            par[y] = x;
            if (rank[x] == rank[y]) ++rank[x];
        }
    }

    bool same(int x, int y) { return (find(x) == find(y)); }
};

bool f[110];

int main() {
    int n, k;
    unionfind uf;
    cin >> n >> k;
    uf.init(n);

    rep(i, n - k + 1) {
        string s;
        cin >> s;
        f[i] = s == "YES";
        if (!f[i]) {
            uf.unite(i, i + k - 1);
        }
    }

    V<string> ans;
    V<string> cand;

    rep(i, 26) {
        string s;
        s.pb('A' + i);
        cand.pb(s);
    }

    rep(i, 26) {
        rep(j, 26) {
            string s;
            s.pb('A' + i);
            s.pb('a' + j);
            cand.pb(s);
        }
    }

    map<int, int> id;

    rep(i, n) {
        int v = uf.find(i);
        if (id.count(v)) {
            ans.pb(cand[id[v]]);
            continue;
        }
        int sz = id.size();
        id[v] = sz;
        ans.pb(cand[id[v]]);
    }
    rep(i, n) cout << ans[i] << (i == n - 1 ? '\n' : ' ');

    return 0;
}