#include<bits/stdc++.h>
#define N 111
using namespace std;
int mp[N][N], w[N][N];
bool vis[N];
int p[N], cnt;
vector<int>v[N];
void dfs(int u, int dp) {
    int sz = v[u].size();
    vis[u] = 1;
    p[dp] = u;
    for(int i = 0; i  < sz; i ++) {
        int ii = v[u][i];
        if(!vis[ii]) dfs(ii, dp + 1);
    }
}
int main(){
   // freopen("AA.in","r",stdin);
    int n, x, y, c;
    scanf("%d", &n);
    int sum = 0;
    for(int i = 1; i <= n; i ++) {
        scanf("%d%d%d", &x, &y, &c);
        v[x].push_back(y);
        v[y].push_back(x);
        mp[x][y] = 1;
        w[x][y] = c;
        sum += c;
    }
    dfs(1, 0);
   // for(int i = 0; i < n; i ++) printf("%d ", p[i]);
    p[n] = 1;
    int ans = 0;
    for(int i = 0; i < n; i ++)
        if(mp[p[i]][p[i+1]]) ans += w[p[i]][p[i+1]];
    printf("%d\n",min(sum - ans, ans));

}