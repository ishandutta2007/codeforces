#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
const int N = (int)1e5 + 50;

int n,m;
vector<int> G[N];
map<P, int> e;
int color[N];
int depth[N], par[N], pp[N];
int u[N];
vector<P> be;
vector<int> res;
int index[N];

int find(int i){return u[i] == i ? i : u[i] = find(u[i]);}
void unite(int i, int j){u[find(i)] = find(j);}

void dfs(int v, int p, int d) {
    color[v] = 1;
    depth[v] = d;
    pp[v] = par[v] = p;
    for(int nxt : G[v]) {
        if(nxt == p) continue;
        if(color[nxt] == -1) dfs(nxt, v, d + 1);
        else if(color[nxt] == 1) be.push_back({v, nxt});
    }
    color[v] = 2;
}

void process() {
    for(int i = 0; i < n; i++) {
        if(color[i] == -1) dfs(i, -1, 0);
    }
    int k = be.size();
    for(int i = 0; i < k; i++) {
        int x = be[i].first;
        vector<int> path;
        while(depth[x] > depth[be[i].second]) {
            path.push_back(x);
            if(index[x] == -1) index[x] = i;
            else unite(index[x], i);
            x = par[x];
        }
        for(int y : path) par[y] = be[i].second;
    }
    vector<int> sizes;
    sizes.resize(k);
    for(int i = 0; i < k; i++){
        sizes[find(i)] ++;
    }
    for(int i = 0; i < k; i++) {
        if(sizes[i] == 1) {
            int u = be[i].first, v = be[i].second;
            res.push_back(e[be[i]]);
            while(u != v) res.push_back(e[{u, pp[u]}]), u = pp[u];
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    fill(color, color + n, -1);
    for(int i = 0; i < n; i++) u[i] = i;
    fill(index, index + n, -1);
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b; a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
        e[{a, b}] = i;
        e[{b, a}] = i;
    }
    process();
    cout << res.size() << endl;
    sort(res.begin(), res.end());
    for(int x : res) cout << x + 1 << " ";
    cout << endl;

}