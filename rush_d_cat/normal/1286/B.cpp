#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
typedef long long LL;
const int N=2000+10;
vector<int> g[N];
int p[N],c[N],sz[N],n,res[N];
vector< pair<int,int> > ans[N];

void dfs(int u) {
    sz[u]=1;
    for(auto v: g[u]) {
        dfs(v); 
        sz[u]+=sz[v];
    }
    if(c[u]>sz[u]-1) {
        printf("NO\n"); exit(0);
    }
    int tot = 0;
    for(auto v: g[u]) {
        for(auto p: ans[v]) {
            ans[u].push_back(make_pair(p.first + tot, p.second));
        }
        //printf("v = %d, sz = %d\n", v, ans[v].size());
        tot += ans[v].size();
    }
    for(int i=0;i<ans[u].size();i++) {
        if (ans[u][i].first >= c[u] + 1) {
            ans[u][i].first ++;
        }
    }
    ans[u].push_back(make_pair(c[u] + 1, u));
}
int main() {
    scanf("%d",&n);
    int rt;
    for(int i=1;i<=n;i++){
        scanf("%d%d",&p[i],&c[i]);
        if(!p[i]) rt=i;
        else g[p[i]].push_back(i);
    }
    dfs(rt);
    printf("YES\n");
    for(auto p: ans[rt]) {
        //printf("[%d, %d]\n", p.first, p.second);
        res[p.second] = p.first;
    }
    for(int i=1;i<=n;i++) printf("%d ", res[i]);
}