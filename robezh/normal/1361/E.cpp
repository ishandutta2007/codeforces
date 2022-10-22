#include <bits/stdc++.h>
using namespace std;

#define lson(x) 2*x+1
#define rson(x) 2*x+2

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<int> vi;
const int N = (int)1e5 + 50;

int n, m;
vi G[N];
int vis[N], dep[N];
int tin[N], tout[N], tim;
int up[N][2];
int gd[N], par[N];
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void dfs1(int v) {
    vis[v] = 1;
    tin[v] = tim++;
    for(int nxt : G[v]) {
        if(!vis[nxt]) dfs1(nxt);
    }
    tout[v] = tim - 1;
}

bool check(int root) {
    bool good = true;
    tim = 0;
    fill(vis, vis + n, 0);
    dfs1(root);
    function<void(int)> dfs = [&](int v) {
        vis[v] = true;
        for(int nxt : G[v]) {
            if(vis[nxt] && !(tin[nxt] <= tin[v] && tout[v] <= tout[nxt])) {
                good = false;
            }
            if(!vis[nxt]) dfs(nxt);
        }
    };
    fill(vis, vis + n, 0);
    dfs(root);
    return good;
}

void dfs2(int v, int d) {
//    cout << "dfs2: " << v << endl;
    vis[v] = 1;
    dep[v] = d;
    up[v][0] = up[v][1] = -1;
    function<void(int)> add = [&](int nxt) {
        if(nxt == -1 || dep[nxt] >= dep[v]) return ;
        for(int i = 0; i < 2; i++) {
            if(up[v][i] == -1) {
                up[v][i] = nxt;
                break;
            }
            if(dep[nxt] < dep[up[v][i]]) swap(nxt, up[v][i]);
        }
    };
    for(int nxt : G[v]) {
        if(vis[nxt]) add(nxt);
        else {
            dfs2(nxt, d + 1);
            add(up[nxt][0]);
            add(up[nxt][1]);
        }
    }
//    cout << v << ", " << up[v][0] << ", " << up[v][1] << endl;
    gd[v] = (up[v][1] == -1);
    par[v] = up[v][0];
}

void dfs3(int v) {
    vis[v] = 1;
    if(par[v] != -1 && !gd[par[v]]) gd[v] = 0;
    for(int nxt : G[v]) {
        if(!vis[nxt]) dfs3(nxt);
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> n >> m;
        rep(i, 0, n) G[i].clear();
        rep(i, 0, m) {
            int a, b;
            cin >> a >> b;
            a--, b--;
            G[a].push_back(b);
        }
        tim = 0;
        int root = -1;
        vi idx(n, 0);
        rep(i, 0, n) idx[i] = i;
        shuffle(all(idx), rng);
        for (int i = 0; i < min(100, sz(idx)); i++) {
            if (check(idx[i])) {
                root = idx[i];
                break;
            }
        }
//        cout << "root: " << root << endl;
        if (root == -1) {
            cout << -1 << '\n';
            continue;
        }
        fill(vis, vis + n, 0);
        dfs2(root, 0);
        fill(vis, vis + n, 0);
        dfs3(root);
        vi res;
        rep(i, 0, n) if (gd[i]) res.push_back(i);
        if(sz(res) * 5 < n) cout << -1 << "\n";
        else {
            for(int x : res) cout << x + 1 << " ";
            cout << '\n';
        }
    }
}