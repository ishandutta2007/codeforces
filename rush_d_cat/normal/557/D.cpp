#include <iostream>
#include <vector>
using namespace std;
typedef long long LL;
const int N=100000+10;
int n,m,col[N],A,B;
vector<int> g[N];
void dfs(int u){
    if(col[u]==1) A++; else B++;

    for(auto v: g[u]){
        if(col[v]==0){
            col[v]=3-col[u]; dfs(v);
        } else {
            if(col[v] == col[u]) {
                printf("0 1\n"); exit(0);
            }
        }
    }
}
int main() {
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int u,v; scanf("%d%d",&u,&v);
        g[u].push_back(v); g[v].push_back(u);
    }
    LL ans=0;
    for(int i=1;i<=n;i++){
        if(col[i]==0) {
            A=B=0;
            col[i]=1;
            dfs(i);
            ans=ans+1LL*A*(A-1)/2 + 1LL*B*(B-1)/2;
        }
    }
    if (ans == 0) {
        if (m==0) {
            cout<<3<<" "<<1LL*n*(n-1)*(n-2)/6<<endl;
        } else {
            LL ans=0;
            for(int i=1;i<=n;i++) {
                if(g[i].size() == 0) ans += m;
                else ans += m-1;
            }
            cout << 2 << " " << ans << endl;
        }
        return 0;
    }
    cout<<1<<" "<<ans<<endl;

}