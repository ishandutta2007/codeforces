#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int M = 1e9 + 7;
const int N = 3e5 + 13;
const int LOGN = 20;

vector<int> g[N];
int p[N], a[N], d[N], tin[N], tout[N];
int T = 1;

void dfs1(int v, int depth) {
    tin[v] = ++T;

    d[v] = depth;

    for(auto u : g[v])
        dfs1(u, depth + 1);

    tout[v] = ++T;
}

int dfs2(int v) {
    int mn = INF;
//    cout << v << endl;
    for(auto u : g[v])
        mn = min(mn, dfs2(u));

    if(mn < INF && (mn < d[a[v]] || mn <= d[v] && mn > d[a[v]])) {
        cout << -1 << endl;
        exit(0);
    }

    return min(mn, d[a[v]]);
}

int main() {
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i++)
        p[i] = -1;

    for(int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u;

        v--;
        u--;

        p[u] = v;
        g[v].push_back(u);
    }

    for(int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }

    for(int i = 0; i < n; i++) {
        if(p[i] == -1)
            dfs1(i, 0);
    }


    for(int i = 0; i < n; i++) {
        if(tin[a[i]] > tin[i] || tout[a[i]] < tout[i]) {
            cout << -1;
            return 0;
        }
    }
//return 0;
    set<pii> st;

    for(int i = 0; i < n; i++) {
        if(p[i] == -1)
            dfs2(i);
        st.insert({-d[a[i]], a[i]});
    }

    cout << st.size() << endl;
    for(auto pr : st)
        cout << pr.s + 1 << endl;
}