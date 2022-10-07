#include<bits/stdc++.h>
using namespace std;
vector<int> v[500009];
vector<int> l[500009];
int n, k;
int f[500009];
long long dp[500009],dp1[500009];
void dfs(int x){
    f[x] = 1;
     vector<long long > V;
    for(int i = 0; i < v[x].size(); i++){
        int y = v[x][i], L = l[x][i];
        if(f[y]) continue;
        dfs(y);
        V.push_back(dp1[y] - dp[y]+L);
        dp[x] += dp[y];
        dp1[x] += dp[y];
    }
    sort(V.rbegin(), V.rend());
    for(int i = 0; i < min(k, (int)V.size()); i++)
    if(V[i] > 0) {dp[x] += V[i];
                    if(i < k-1) dp1[x] += V[i];}
}
void solve(){
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; i++){
        f[i] = 0; dp[i] = 0; dp1[i] = 0;
        v[i].clear(); l[i].clear();}
    for(int i = 1; i <= n-1; i++){
        int a,b ,c;
        scanf("%d %d %d", &a,&b,&c);
        v[a].push_back(b);
        v[b].push_back(a);
        l[a].push_back(c);
        l[b].push_back(c);
    }

    dfs(1);
    printf("%lld\n", dp[1]);
}
main(){
    int q;
    cin >> q;
    while(q--){
        solve();
    }


}