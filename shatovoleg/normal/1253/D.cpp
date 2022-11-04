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

vector<vector<int>> g;
vector<int> used;

int get_min(int v) {
    int ans = v;
    used[v] = 1;
    for (auto &x : g[v]) {
        if (used[x] == 0) {
            cmin(ans, get_min(x));
        }
    }
    return ans;
}

int get_max(int v) {
    int ans = v;
    used[v] = 2;
    for (auto &x : g[v]) {
        if (used[x] == 1) {
            cmax(ans, get_max(x));
        }
    }
    return ans;
}

void run() {
    int n, m;
    cin >> n >> m;
    g.resize(n);
    used.resize(n, 0);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].pb(v);
        g[v].pb(u);
    }
    vector<pii> segs;
    for (int i = 0; i < n; ++i) {
        if (used[i] != 0) {
            continue;
        }
        segs.emplace_back();
        segs.back().first = get_min(i);
        segs.back().second = get_max(i);
    }
    int last = -1, cnt = 0;
    sort(all(segs));
    for (auto &[l, r] : segs) {
        if (l > last) {
            ++cnt;
        }
        cmax(last, r);
    }
    cout << len(segs) - cnt << endl;
}