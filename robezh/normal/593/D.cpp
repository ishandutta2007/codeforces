#include <bits/stdc++.h>
using namespace std;

const int N = (int)2e5 + 50;
typedef long long ll;
typedef pair<int, int> P;

int n, m;
vector<int> G[N];
int f[N], dep[N], par[N];
int id_to_edge[N];
ll cst[N];
map<P, int> mp;

void dfs(int v, int p, int d) {
    f[v] = v;
    dep[v] = d;
    par[v] = p;
    if(p != -1) id_to_edge[v] = mp[{v, p}];
    for(int nxt : G[v]) if(nxt != p) {
        dfs(nxt, v, d + 1);
    }
}

int find(int v) {
    if(f[v] != 0 && cst[id_to_edge[f[v]]] == 1) {
        return f[v] = find(par[f[v]]);
    }
    return f[v];
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i < n - 1; i++) {
        int a, b; ll c; cin >> a >> b >> c; a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
        cst[i] = c;
        mp[{a, b}] = mp[{b, a}] = i;
    }
    dfs(0, -1, 0);
    for(int i = 0; i < m; i++) {
        int tp; cin >> tp;
        if(tp == 1) {
            int a, b; ll y;
            cin >> a >> b >> y; a--, b--;
            a = find(a);
            b = find(b);
            while(y > 0 && a != b) {
                if(dep[a] < dep[b]) swap(a, b);
                y /= cst[id_to_edge[a]];

                a = find(par[a]);
            }
            cout << y << "\n";
        }
        else {
            int id; ll val;
            cin >> id >> val; id--;
            cst[id] = val;
        }
    }
}