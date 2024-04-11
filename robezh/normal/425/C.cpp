#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e5 + 500, W = 305, INF = (int)1e9 + 500;

int n,m,s,e;
int a[N], b[N];
vector<int> loc[N];
int dp[N][W], pmin[N][W];

int main(){
    scanf("%d%d%d%d", &n, &m, &s, &e);
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        loc[a[i]].push_back(i);
    }
    for(int i = 1; i <= m; i++) scanf("%d", &b[i]);

    for(int i = 0; i <= m; i++){
        fill(dp[i], dp[i] + W, INF);
        fill(pmin[i], pmin[i] + W, INF);
    }
    dp[0][0] = pmin[0][0] = 0;
    int res = 0;
    for(int i = 1; i <= m; i++){
        pmin[i][0] = pmin[i-1][0];
        for(int j = 1; j < W; j++){
            auto mn = upper_bound(loc[b[i]].begin(), loc[b[i]].end(), pmin[i-1][j-1]);
            if(mn != loc[b[i]].end()) dp[i][j] = min(dp[i][j], *mn);
            pmin[i][j] = min(pmin[i-1][j], dp[i][j]);
            if(dp[i][j] + i <= s - e * j) res = max(res, j);
        }
    }
    cout << res << endl;
}