#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define pb push_back
#define kek pop_back
#define mp make_pair
#define pii pair<int, int>
#define all(v) v.begin(), v.end()
#define len(v) ((int)(v).size())
#define int ll

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
const int INF = 1e9;

template<class t1, class t2>
bool cmin(t1 &a, const t2 &b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

template<class t1, class t2>
bool cmax(t1 &a, const t2 &b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

#ifndef LOCAL
void UseFiles(const string &s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}
#else
void UseFiles(const string&) {}
#endif

void run();

signed main() {
    iostream::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    run();
}

int get_dist(const pii &a, const pii &b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

struct Dsu {
    vector<int> l, h;

    Dsu(int n) : l(n), h(n, 1) {
        iota(all(l), 0);
    }

    int get_root(int v) {
        if (v == l[v]) {
            return v;
        }
        return l[v] = get_root(l[v]);
    }

    bool Union(int u, int v) {
        u = get_root(u);
        v = get_root(v);
        if (u == v) {
            return false;
        }
        if (h[u] > h[v]) {
            swap(u, v);
        }
        l[u] = v;
        if (h[v] == h[u]) {
            ++h[v];
        }
        return true;
    }
};

void run() {
    int n;
    cin >> n;
    vector<pii> points(n);
    for (auto &[x, y] : points) {
        cin >> x >> y;
    }
    Dsu d(n + 1);
    vector<int> c(n);
    for (auto &x : c) {
        cin >> x;
    }
    vector<int> k(n);
    for (auto &x : k) {
        cin >> x;
    }
    vector<tuple<int, int, int>> edges;
    for (int i = 0; i < n; ++i) {
        edges.pb({c[i], i, n});
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            edges.pb({(k[i] + k[j]) * get_dist(points[i], points[j]), i, j});
        }
    }
    sort(all(edges));
    int ans = 0;
    vector<int> cit;
    vector<pii> pairs;
    for (auto &[w, a, b] : edges) {
        if (d.Union(a, b)) {
            ans += w;
            if (b == n) {
                cit.pb(a);
            } else {
                pairs.pb({a, b});
            }
        }
    }
    cout << ans << endl;
    cout << len(cit) << endl;
    for (auto &x : cit) {
        cout << x + 1 << " ";
    }
    cout << endl;
    cout << len(pairs) << endl;
    for (auto &[x, y] : pairs) {
        cout << x + 1 << " " << y + 1 << endl;
    }
}