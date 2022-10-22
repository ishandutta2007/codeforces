#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N = 100050, INF = (int)1e9;
const int LOGN = 17;
int root = 0;
int n, k;

vector<int> G[N];
int parent[LOGN][N];
int depth[N];
int tin[N], tout[N], tim;
void dfs(int v, int p, int d){
    parent[0][v] = p;
    depth[v] = d;
    tin[v] = tim++;
    for(int nxt : G[v]){
        if(nxt != p) dfs(nxt, v, d+1);
    }
    tout[v] = tim - 1;
}

void init(){
    dfs(root, -1, 0);

    for(int k = 0; k+1 < LOGN; k++){
        for(int v = 0; v < n; v++){
            if(parent[k][v] < 0) parent[k+1][v] = -1;
            else parent[k+1][v] = parent[k][parent[k][v]];
        }
    }
}

int lca(int u, int v){
    if(depth[u] > depth[v]){int tmp = u; u = v; v = tmp;}
    for(int k = 0; k < LOGN; k++){
        if((depth[v] - depth[u]) >> k & 1){
            v = parent[k][v];
        }
    }
    if(u == v) return u;
    for(int k = LOGN - 1; k >= 0; k--){
        if(parent[k][u] != parent[k][v]){
            u = parent[k][u];
            v = parent[k][v];
        }
    }
    return parent[0][u];
}

int getdis(int u, int v){
    int ca = lca(u, v);
    return depth[u] + depth[v] - 2 * depth[ca];
}

set<pii> S;

int count(int v) {
    if(S.empty()) return 0;
    auto it = S.lower_bound({tin[v], v});
    if(it == S.begin() || it == S.end()) {
        int a = S.begin() -> second;
        int b = S.rbegin() -> second;
        return (getdis(a, v) + getdis(b, v) - getdis(a, b)) / 2;
    }
    else {
        auto pit = it; pit--;
        int a = pit -> second, b = it -> second;
        return (getdis(a, v) + getdis(b, v) - getdis(a, b)) / 2;
    }
}

int cursize = 1;

void add(int v) {
    cursize += count(v);
    S.insert({tin[v], v});
}


void del(int v) {
    S.erase({tin[v], v});
    cursize -= count(v);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    rep(i, 0, n - 1) {
        int a, b; cin >> a >> b; a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    init();
    int res = 0;
    int r = 1;
    S.insert({tin[0], 0});
    for(int i = 0; i < n; i++) {
        while(r < n) {
            add(r);
            if(cursize > k) {
                del(r);
                break;
            }
            r++;
        }
//        cout << i + 1 << " " << r << " " << cursize << endl;
        res = max(res, r - i);
        del(i);
//        cout << i + 2 << " " << r << " " << cursize << endl;
    }
    cout << res << '\n';
}