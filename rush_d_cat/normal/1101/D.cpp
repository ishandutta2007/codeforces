#include <iostream>
#include <vector>
#include <map>
using namespace std;
const int N=200000+10;
vector<int> d[N],g[N];
int n,ans,a[N],vis[N];
map<int,int> mp[N],mx1[N],mx2[N];

void dfs(int u,int p){
    for(auto v:g[u]){
        if(v==p)continue;
        dfs(v,u);
        for(auto x:d[a[u]]){
            mp[u][x]=max(mp[v][x]+1, mp[u][x]);
            if(mp[v][x]>mx1[u][x]){
                mx2[u][x]=mx1[u][x];
                mx1[u][x]=mp[v][x];
            } else if(mp[v][x]>mx2[u][x]){
                mx2[u][x]=mp[v][x];
            }
        }
    }
    for(auto x:d[a[u]]){
        mp[u][x]=max(mp[u][x],1);
        ans=max(ans,1+mx1[u][x]+mx2[u][x]);
    }
}
int main(){
    for(int i=2;i<N;i++){
        if(vis[i]) continue;
        for(int j=i;j<N;j+=i) {
            d[j].push_back(i), vis[j]=1;
        }
    }
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=2;i<=n;i++){
        int u,v; scanf("%d%d",&u,&v);
        g[u].push_back(v); g[v].push_back(u);
    }
    dfs(1,1);
    cout<<ans<<endl;
}