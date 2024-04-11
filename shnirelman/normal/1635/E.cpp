#include <bits/stdc++.h>

#define f first
#define s second
//#define x first
//#define y second
//#define int li
#define err if(debug_out)cout

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
using pld = pair<ld, ld>;

const int INF = 1e9 + 13;
const li INF64 = 1e18 + 13;
const int N = 2e5 + 13;
const int LOGN = 20;
const int K = 22;
const int M = 1e9 + 7;
//const int M = 998244353;
//const int A = 26;
const ld eps = 1e-8;

mt19937 rnd(45768);

/*
*/

void NO() {
    cout << "NO" << endl;
    exit(0);
}

vector<int> g[N];
int used[N];
int col[N];

void dfs1(int v, int cl) {
    used[v] = 2;
    col[v] = cl;

    for(int u : g[v]) {
        if(!used[u])
            dfs1(u, cl ^ 1);
        else if(col[u] == col[v]) {
            NO();
        }
    }
}

vector<int> g2[N];
vector<int> ts;

void dfs2(int v) {
    used[v] = 1;

//    cout << "dfs2 " << v << endl;

    for(int u : g2[v]) {
//        cout << "go " << v << " -> " << u << endl;
        if(used[u] == 1)
            NO();
        else if(used[u] == 0)
            dfs2(u);
    }

    used[v] = 2;
    ts.push_back(v);
}

pii e[N];
int tp[N];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int v, u;
        cin >> tp[i] >> v >> u;

        v--;
        u--;

        e[i] = {v, u};

        g[v].push_back(u);
        g[u].push_back(v);

//        if(tp[i] == 1) {
//
//        }
    }

    for(int i = 0; i < n; i++) {
        if(!used[i]) {
            dfs1(i, 0);
        }
    }

    for(int i = 0; i < m; i++) {
//        if(tp[i] == 1 && col[e[i].f] == 0 || tp[i] == 2 && col[e[i].f] == 1)
        if(tp[i] - 1 == col[e[i].f]) {

            g2[e[i].s].push_back(e[i].f);
        } else {
            g2[e[i].f].push_back(e[i].s);
        }
    }

    for(int i = 0; i < n; i++) {
        used[i] = 0;
    }

    for(int i = 0; i < n; i++) {
        if(!used[i]) {
            dfs2(i);
        }
    }

    cout << "YES\n";

    vector<int> wh(n);
    for(int i = 0; i < n; i++) {
        wh[ts[i]] = i;
    }

    for(int i = 0; i < n; i++) {
        cout << (col[i] == 0 ? 'L' : 'R') << ' ' << wh[i] << '\n';
    }
}