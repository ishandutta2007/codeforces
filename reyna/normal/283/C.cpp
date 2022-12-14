// In the name of God
#include <iostream>
using namespace std;
typedef long long ll;
const int Mod = 1e9+7;
const int Maxn = 300+20;
int val[Maxn];
int use[Maxn];
int next[Maxn];
int vis[Maxn];
int prev[Maxn];
int mark[Maxn];
ll dp[100000+20];
bool flag;
int dfs(int v){
    if(vis[v]){
        flag = 1;
        return 0;
    }
    vis[v] = true;
    int ret = 0;
    if(next[v] != -1)
        ret+=dfs(next[v]);
    return val[v] = ret + val[v];
}
int main(){
    int n,q,k;
    cin >> n >> q >> k;
    for(int i = 0; i < n;i++)
        cin >> val[i];
    for(int i = 0; i < n;i++){
        next[i] = -1;
        prev[i] = -1;
    }
    for(int i = 0; i < q;i++){
        int u,v;
        cin >> u >> v;
        next[--v] = --u;
        prev[u] = v;
    }
    for(int i = 0; i < n;i++)
        if(next[i] != -1)
            mark[next[i]] = true;
    for(int i = 0; i < n;i++)
        if(prev[i] != -1)
            use[prev[i]] = true;
    for(int i = 0; i < n;i++){
        if(!mark[i])
            dfs(i);
    }
//  for(int i = 0; i < n;i++)
//      cout << val[i] << " " << i << endl;
    for(int i = 0; i < n;i++)
        if(!vis[i])
            flag = 1;
    if(flag){
        cout << 0 << endl;
        return 0;
    }
    ll sum = 0;
    for(int i = 0; i < n;i++)
        if(mark[i])
            sum+=val[i];
//  cout << sum << endl;
    if(sum > k){
        cout << 0 << endl;
        return 0;
    }
    dp[sum] = 1;
    for(int i = 0; i < n;i++){
        for(int j = 0; j <= k; j++){
            if(j >= val[i])
                dp[j] += dp[j-val[i]];
            dp[j]%=Mod;
        }
    }
    cout << dp[k] << endl;
    return 0;
}