//In the name of God
#include <iostream>
#include <vector>
using namespace std;
const int Maxn = 230;
vector<int> al[Maxn];
int dp[Maxn][Maxn];
int path[Maxn][Maxn];
void dfs1(int v,int p,int ans,int now){
    if(ans != v)
        path[ans][v] = now;
    for(int i = 0; i < al[v].size();i++){
        int u = al[v][i];
        if(u == p)
            continue;
        if(ans == v)
            dfs1(u,v,ans,u);
        else
            dfs1(u,v,ans,now);
    }
    return;
}
int dfs2(int v,int p,int upd){
    int sMax = -1,Max = -1;
    for(int i = 0; i < al[v].size();i++){
        int u = al[v][i];
        if(u == p)
            continue;
        int tmp = dfs2(u,v,upd);
        if(tmp >= Max){
            sMax = Max;
            Max = tmp;
        }else
            sMax = max(sMax,tmp);
    }
    if(upd == v){
        return sMax + Max + 2;
    }
    else
        return Max+1;
}
int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n-1;i++){
        int u,v;
        cin >> u >> v;
        al[--u].push_back(--v);
        al[v].push_back(u);
    }
    for(int i = 0; i < n;i++)
        dfs1(i,-1,i,i);
    for(int i = 0; i < n;i++)
        for(int j = 0; j < al[i].size();j++)
            if(i != al[i][j]){
                dp[i][al[i][j]] = dfs2(i,al[i][j],i);
            //  cerr << dp[i][al[i][j]] << " " << i << " " << al[i][j] << endl;
            }
    int ans = 0;
    for(int i = 0; i < n;i++)
        for(int j = 0; j < n;j++)
            if(i != j)
                ans = max(ans,dp[i][path[i][j]] * dp[j][path[j][i]]);
    cout << ans << endl;
    return 0;
}