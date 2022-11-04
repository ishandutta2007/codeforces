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

set<pii> edges;

bool check_edge(int u, int v) {
    if (u > v) {
        swap(u, v);
    }
    return edges.count({u, v});
}

void add_edge(int u, int v) {
    if (u > v) {
        swap(u, v);
    }
    edges.insert({u, v});
}

void run() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        add_edge(u, v);
    }
    set<int> unvisited;
    for (int i = 0; i < n; ++i) {
        unvisited.insert(i);
    }
    int cnt = 0;
    while (len(unvisited)) {
        ++cnt;
        queue<int> q;
        q.push(*unvisited.begin());
        unvisited.erase(unvisited.begin());
        while (len(q)) {
            int v = q.front();
            q.pop();
            vector<int> deleted;
            for (auto &x : unvisited) {
                if (!check_edge(x, v)) {
                    deleted.pb(x);
                    q.push(x);
                }
            }
            for (auto &x : deleted) {
                unvisited.erase(x);
            }
        }
    }
    cout << cnt - 1 << endl;
}