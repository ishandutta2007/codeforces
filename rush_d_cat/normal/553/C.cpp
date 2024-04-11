#include <iostream>
#include <set>
#include <vector>
using namespace std;
typedef long long LL;
const int N=1000000+10;
const LL MOD = 1e9+7;
int n,m,a[N],b[N],c[N];
int par[N];
vector<int> g[N];
int find(int x){
    return par[x]==x?x:par[x]=find(par[x]);
}
int col[N];
void dfs(int u){
    for(auto v: g[u]) {
        if(col[v]==0){
            col[v]=3-col[u]; dfs(v);
        } else {
            if(col[v]==col[u]){
                printf("0\n");exit(0);
            }
        }
    }
}
int main() {
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)par[i]=i;
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&a[i],&b[i],&c[i]);
        if(c[i]==1) {
            par[find(a[i])]=find(b[i]);
        }
    }
    for(int i=1;i<=m;i++){
        if(c[i]==0){
            if(find(a[i])==find(b[i])){
                return !printf("0\n");
            } 
            g[find(a[i])].push_back(find(b[i]));
            g[find(b[i])].push_back(find(a[i]));
        }
    }
    LL ans=1;
    for(int i=1;i<=n;i++){
        if(col[find(i)]==0){
            col[find(i)]=1;
            dfs(find(i)); ans=ans*2%MOD;
        }
    }
    ans=ans*(MOD+1)/2 % MOD;
    cout<<ans<<endl;
}