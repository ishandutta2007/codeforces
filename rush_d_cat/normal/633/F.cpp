#include <iostream>
#include <vector>
#include <set>
using namespace std;
typedef long long LL;
const int N = 100000+10;
vector<int> g[N]; int n,a[N];
LL dp[N],up[N],down[N];
void dfs1(int u,int p){
    for(auto v:g[u]){
        if(v==p)continue;
        dfs1(v,u); down[u]=max(down[u],down[v]);
    }
    down[u] += a[u];
}
void dfs2(int u,int p){
    LL mx=0;dp[u]=down[u];
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i];if(v==p)continue;
        dp[u]=max(dp[u],a[u]+down[v]+mx);
        up[v]=max(up[u]+a[u],up[v]); 
        up[v]=max(mx+a[u],up[v]);
        mx=max(mx,down[v]);
    } 
    mx=0;
    for(int i=g[u].size()-1;i>=0;i--){
        int v=g[u][i]; if(v==p)continue;
        up[v]=max(mx+a[u],up[v]);
        mx=max(mx,down[v]);
    }
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i]; if(v==p)continue;
        dfs2(v,u); dp[u] = max(dp[u],dp[v]);
    }    
}

LL ans=0;
void dfs3(int u,int p){
    LL mx=0;
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i]; if(v==p)continue;
        ans = max(ans, up[u] + a[u] + down[v] + mx);
        ans = max(ans, mx + dp[v]);
        mx = max(mx, dp[v]);
    }
    mx = 0;
    for(int i=g[u].size()-1;i>=0;i--){
        int v=g[u][i]; if(v==p)continue;
        ans = max(ans, up[u] + a[u] + down[v] + mx);
        mx = max(mx, dp[v]);  
        dfs3(v,u);      
    }
}
void dfs4(int u,int p){
    multiset<LL> st;
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i]; if(v==p)continue;
        st.insert(down[v]);
    }
    if(st.size()>=2) {
        LL mx = *st.rbegin(); st.erase(st.find(mx));
        LL mxx= *st.rbegin(); st.erase(st.find(mxx)); 
        ans = max(ans, mx+mxx+a[u]+up[u]);
        st.insert(mx); st.insert(mxx);
    }   
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i]; if(v==p)continue;
        dfs4(v,u);
        if(st.size()<=2)continue;
        //printf("%d -> %d\n", u,v);
        st.erase(st.find(down[v]));
        LL mx = *st.rbegin(); st.erase(st.find(mx));
        LL mxx= *st.rbegin(); st.erase(st.find(mxx)); 
        st.insert(mx); st.insert(mxx);
        st.insert(down[v]);  
        ans = max(ans, mx+mxx+a[u] + dp[v]);   
    }
}
int main() {

    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=2;i<=n;i++){
        int u,v; scanf("%d%d",&u,&v);
        g[u].push_back(v); g[v].push_back(u);
    }
    dfs1(1,1); dfs2(1,1); dfs3(1,1);dfs4(1,1);
    for(int i=1;i<=n;i++) {
        //printf("i=%d, up=%lld, down=%lld, dp=%lld\n", i,up[i],down[i],dp[i]);
    }
    ans=max(ans,dp[1]);
    cout<<ans<<endl;
}