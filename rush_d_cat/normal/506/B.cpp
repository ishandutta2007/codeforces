#include <iostream>
#include <set>
#include <vector>
#include <cstring>
using namespace std;
const int NICO = 100002;

vector<int> G[NICO], rG[NICO], vs;
int us[NICO], cmp[NICO], cmp_size[NICO];
int n, m;

void dfs(int x)
{
    us[x] = 1;
    for(int i=0;i<G[x].size();i++)
    {
        if(!us[G[x][i]]) dfs(G[x][i]);
    }
    vs.push_back(x);
}

void rdfs(int x, int k)
{
    us[x] = 1, cmp[x] = k;
    for(int i=0;i<rG[x].size();i++)
    {
        if(!us[rG[x][i]]) rdfs(rG[x][i], k);
    }
}

int scc()
{
    memset(us,0,sizeof(us));
    for(int i=1;i<=n;i++)
    {
        if(!us[i]) dfs(i);
    }
    int k = 0;
    memset(us,0,sizeof(us));
    for(int i=vs.size()-1;i>=0;i--)
    {
        if(!us[vs[i]]) rdfs(vs[i], k++);
    }
    return k;
}

int dfs2(int x) {
    us[x] = 1;
    int res = (cmp_size[cmp[x]] == 1);
    for(int i=0;i<G[x].size();i++) if(!us[G[x][i]]){
        res &= dfs2(G[x][i]);
    }
    for(int i=0;i<rG[x].size();i++) if(!us[rG[x][i]]){
        res &= dfs2(rG[x][i]);
    }    
    return res;
}

int main() {
    scanf("%d %d", &n, &m);

    for(int i=1;i<=m;i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        G[u].push_back(v);
        rG[v].push_back(u);
    }

    scc();
    for(int i=1;i<=n;i++) {
        cmp_size[cmp[i]] ++;
    }

    int ans = n;

    memset(us, 0, sizeof(us));
    for(int i=1;i<=n;i++) if(!us[i]) {
        ans -= dfs2(i);
    }

    printf("%d\n", ans);
}