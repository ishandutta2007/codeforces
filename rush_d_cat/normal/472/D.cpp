#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 2002;
const int INF = 1e9 + 7;
int n, dd[N][N];
int d[N][N],vis[N];
int par[N];
int src;
vector< pair<int,int> > edge[N*N];
vector< pair<int,int> > g[N];
void dfs(int u,int p) {
    for(auto x: g[u]) {
        int v = x.first; if(p==v) continue;
        int w = x.second;
        dd[src][v] = dd[src][u] + w;
        dfs(v, u);
    }
}
int find(int x) {
    return par[x]==x?x:par[x]=find(par[x]);
}
vector<int> v;
int id(int x) {
    return lower_bound(v.begin(), v.end(), x) - v.begin() + 1;
}


int main() {
    scanf("%d", &n);
    for(int i=1;i<=n;i++) par[i] = i;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            scanf("%d", &d[i][j]);
        }
    }
    for(int i=1;i<=n;i++) if(d[i][i]) return !printf("NO\n");
    for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) {
        if (d[i][j] == 0) return !printf("NO\n");
        if (d[i][j] != d[j][i]) return !printf("NO\n");
    }
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            v.push_back(d[i][j]);
        }
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++)
        edge[id(d[i][j])].push_back(make_pair(i, j));
    }
    for(int i=1;i<=v.size();i++) {
        for(auto p: edge[i]) {
            if (find(p.first) != find(p.second)) {
                par[find(p.first)] = find(p.second);
                int w = d[p.first][p.second];
                g[p.first].push_back(make_pair(p.second, w));
                g[p.second].push_back(make_pair(p.first, w));
            }
        }
    }
    for(src = 1; src <= n; src ++) {
        dfs(src, src);
    }
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            if(d[i][j]!=dd[i][j]) {
                return !printf("NO\n");
            }
        }
    }
    printf("YES\n");
}