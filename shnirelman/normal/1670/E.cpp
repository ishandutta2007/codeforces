#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const li INF64 = 1e18 + 13;
const int N = 1e6 + 13;
const int K = 17;
const int M = 1e9 + 7;
const int LOGN = 20;

int n;
vector<int> g[N];
pii e[N];
//int d[N];
//int col[N];
//int cnt[2];
int res[N];
int cur = 1;

void dfs(int v, int par, bool fl) {

    for(int ed : g[v]) {
        int u = e[ed].f ^ e[ed].s ^ v;

        if(u == par)
            continue;

        if(!fl) {
            res[u] = cur;
            res[ed + n] = cur + n;
        } else {
            res[u] = cur + n;
            res[ed + n] = cur;
        }

        cur++;
        dfs(u, v, !fl);
    }
}



void solve() {
    int p;
    cin >> p;

    n = (1 << p);

//    cnt[0] = cnt[1] = 0;
    cur = 1;
    for(int i = 0; i < n; i++) {
        g[i].erase(g[i].begin(), g[i].end());
//        d[i] = INF;
//        col[i] = 0;
//        res[i] = 0;
    }

    for(int i = 0; i < n * 2; i++) {
        res[i] = 0;
    }

    for(int i = 0; i < n - 1; i++) {
        int v, u;
        cin >> v >> u;

        v--;
        u--;

        e[i] = {v, u};
        g[v].push_back(i);
        g[u].push_back(i);

//        g[v].push_back(i + n);
//        g[u].push_back(i + n);
//        g[i + n].push_back(v);
//        g[i + n].push_back(u);
    }


    res[0] = n;
    dfs(0, -1, false);

    cout << 1 << '\n';
    for(int i = 0; i < n; i++)
        cout << res[i] << ' ';
    cout << '\n';
    for(int i = n; i < n * 2 - 1; i++)
        cout << res[i] << ' ';
    cout << '\n';
//    dfs(root, -1, 0, n);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
        solve();
}