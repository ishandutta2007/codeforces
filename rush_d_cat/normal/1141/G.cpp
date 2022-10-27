#include <iostream>
#include <map>
#include <vector>
using namespace std;
const int N = 200000 + 10;

int n,k,deg[N],cnt[N],x[N],y[N], r;
vector<int> g[N];

map< pair<int,int>, int > ans;
void dfs(int u, int p, int col) {
    int now = 0;
    ans[make_pair(u,p)] = ans[make_pair(p,u)] = col;
    for(auto v: g[u]) {
        if (v == p) continue;
        if (g[u].size() <= r) {
            if (now + 1 == col) ++ now;
            dfs(v, u, ++now);
        } else {
            dfs(v, u, 1);
        }
    }
}
int main() {
    scanf("%d%d",&n,&k);
    for(int i=1;i<n;i++) {
        int u,v; scanf("%d%d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
        deg[u]++, deg[v]++; 
        x[i]=u,y[i]=v;
    }
    for(int i=1;i<=n;i++)
        cnt[deg[i]] ++;

    int sum=0;
    for(int i=1;i<=n;i++) {
        sum += cnt[i]; 
        if (sum >= n-k) {
            r = i; break;
        }
    }   
    dfs(1,0,0);
    printf("%d\n", r);
    for(int i=1;i<n;i++)
        printf("%d ", ans[make_pair(x[i], y[i])]);

}