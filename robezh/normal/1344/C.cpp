#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N = (int)5e5 + 50;

int n, m;
int vis[N][2];
int in[N];
vi G[N][2];
int ord[N], t;
int res[N];

void dfs(int v, int c) {
    vis[v][c] = 1;
    for(int nxt : G[v][c]) {
        if(!vis[nxt][c]) dfs(nxt, c);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b; a--, b--;
        G[a][0].push_back(b);
        G[b][1].push_back(a);
        in[b]++;
    }
    queue<int> que;
    rep(i, 0, n) if(!in[i]) que.push(i);
    while(!que.empty()) {
        int v = que.front(); que.pop();
        ord[v] = t++;
        for(int nxt : G[v][0]) {
            in[nxt]--;
            if(!in[nxt]) que.push(nxt);
        }
    }
//    cout << t << endl;
    if(t != n) return cout << -1 << '\n', 0;
    int tot = 0;
    for(int i = 0; i < n; i++) {
        res[i] = (vis[i][0] || vis[i][1] ? 0 : 1);
        tot += res[i];
        dfs(i, 0);
        dfs(i, 1);
    }
    cout << tot << '\n';
    for(int i = 0; i < n; i++) cout << (res[i] ? 'A' : 'E');
}