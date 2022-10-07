#include<bits/stdc++.h>
#define ll long long
using namespace std;
int I,J;
vector<int> v[3009];
int l[3009][3009];
ll dp[3009][3009];
int sz[3009][3009];
int f[3009];
int nx[3009][3009];
vector<pair<int,int> > q[3009];
void dfs(int x, int d){
    f[x] =I;
    l[I][x] = d;
    nx[I][x] = J;
    sz[I][x] = 1;
    for(int y : v[x]){
        if(f[y] == I) continue;
        dfs(y, d+1);
        sz[I][x] += sz[I][y];
    }
}
main(){
    int n;
    cin >> n;
    for(int i=1; i <= n-1; i++){
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i =1; i <= n; i++){
        I = i;
        f[i] = i;
        sz[I][I] = n;
        for(int j : v[i]){
            J = j;
            dfs(j,1);
        }
    }
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++){
            if(i == j) continue;
            if(l[i][j] == 1) dp[i][j] = sz[i][j] * sz[j][i];
            else q[l[i][j]].push_back({i,j});
        }
    for(int L =2; L <= n; L++){
        for(auto x : q[L]){
            int a = x.first, b = x.second;
            dp[a][b] = sz[a][b] * sz[b][a] + max(dp[nx[a][b]][b], dp[nx[b][a]][a]);
        }
    }
    ll ans = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            ans = max(ans, dp[i][j]);
    cout<<ans<<endl;
}