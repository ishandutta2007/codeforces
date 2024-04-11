#include<bits/stdc++.h>
using namespace std;

#define N 250010
#define L 18

int p[N], d[N], f[N][L];
vector <int> order, av[N], bv[N];

void dfs1(int x, int pa) {
    p[x] = pa;
    for(int i = 0; i < av[x].size(); i ++) {
        int y = av[x][i];
        if(y == pa) continue;
        dfs1(y, x);
    }
    if(x > 1) order.push_back(x);
}

void dfs(int x, int pa) {
    f[x][0] = pa;
    d[x] = d[pa] + 1;
    for(int i = 1; i < L; i ++) f[x][i] = f[f[x][i-1]][i-1];
    for(int i = 0; i < bv[x].size(); i ++) {
        int y = bv[x][i];
        if(y == pa) continue;
        dfs(y, x);
    }
}

int anc(int x, int y) {
    for(int i = 31 - __builtin_clz(y); i >= 0; i --) if(y & (1 << i)) x = f[x][i];
    return x;
}

int lca(int x, int y) {
    if(d[x] > d[y]) x = anc(x, d[x] - d[y]);
    else if(d[y] > d[x]) y = anc(y, d[y] - d[x]);
    if(x == y) return x;
    for(int i = 31 - __builtin_clz(d[x]); i >= 0; i --) if(f[x][i] != f[y][i]) x = f[x][i], y = f[y][i];
    return f[x][0];
}

int root[N];
int find(int x) {return root[x] == x ? x : root[x] = find(root[x]);}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1, x, y; i < n; i ++) {
        cin >> x >> y;
        bv[x].push_back(y);
        bv[y].push_back(x);
    }
    dfs(1, 0);
    for(int i = 1, x, y; i < n; i ++) {
        cin >> x >> y;
        av[x].push_back(y);
        av[y].push_back(x);
    }
    dfs1(1, 0);
    typedef pair <int, int> pii;
    typedef pair <pii, pii> ppp;
    vector <ppp> ans;
    for(int i = 1; i <= n; i ++) root[i] = i;
    for(int i = 0; i < order.size(); i ++) {
        int x = order[i];
        int y = p[x];
        int z = lca(x, y);
        pii p1(x, y);
        if(find(z) == x) {
            for(int i = L-1; i >= 0; i --) {
                int w = f[y][i];
                if(d[w] <= d[z]) continue;
                if(find(w) == x) z = w;
                else y = w;
            }
            ans.push_back(ppp(p1, pii(y, z)));
            root[x] = find(y);
        }
        else {
            y = x;
            for(int i = L-1; i >= 0; i --) {
                int w = f[x][i];
                if(d[w] <= d[z]) continue;
                if(find(w) == y) x = w;
                else z = w;
            }
            ans.push_back(ppp(p1, pii(x, z)));
            root[y] = find(z);
        }
    }
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i ++) {
        cout << ans[i].second.first << ' ' << ans[i].second.second << ' ';
        cout << ans[i].first.first << ' ' << ans[i].first.second << endl;
    }
}