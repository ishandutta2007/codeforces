#include <iostream>
#include <vector>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int n,sz[N],col[N];
vector<int> g[N]; LL ans=0,cnt=0;
void dfs(int u,int p){
    col[u] = col[p] ^ 1; sz[u] = 1;
    if(col[u]==0) cnt++;
    for(auto v: g[u]) {
        if(p==v) continue;
        dfs(v, u); ans = ans + 1LL * sz[v] * (n - sz[v]);
        sz[u] += sz[v];
    }
}
int main() {
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        int u,v; scanf("%d%d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,1);
    ans = ans + cnt*(n-cnt);
    ans/=2;
    cout<<ans<<endl;
}