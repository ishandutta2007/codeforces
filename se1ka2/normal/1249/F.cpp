#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> P;

int n, k;
int a[203];
vector<int> g[203];
int dp[203][203];

void dfs(int now, int par){
    for(int next : g[now]){
        if(next != par) dfs(next, now);
    }
    dp[now][0] = a[now];
    for(int dep = 0; dep < n; dep++){
        for(int next : g[now]){
            if(next == par) continue;
            if(dep == 0){
                dp[now][dep] += dp[next][k - 1];
                continue;
            }
            int sum = dp[next][dep - 1];
            for(int other : g[now]){
                if(other == next || other == par) continue;
                sum += dp[other][max(dep - 1, k - dep - 1)];
            }
            dp[now][dep] = max(dp[now][dep], sum);
        }
    }
    for(int dep = n - 2; dep >= 0; dep--){
        dp[now][dep] = max(dp[now][dep], dp[now][dep + 1]);
    }
}

int main()
{
    cin >> n >> k;
    k++;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(0, -1);
    cout << dp[0][0] << endl;
}