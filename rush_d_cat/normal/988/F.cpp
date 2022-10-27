#include <iostream>
#include <algorithm>
using namespace std;
const int INF = 1000000007;
const int N = 2002;
pair<int,int> seg[N], umb[N];
int a,n,m,rain[N],id[N];

int dp[N][N];

int main() {
    scanf("%d %d %d", &a, &n, &m);
    for (int i=1;i<=n;i++) {
        scanf("%d%d",&seg[i].first,&seg[i].second);
        for(int j=seg[i].first+1;j<=seg[i].second;j++) 
            rain[j]=1; 
    }
    for (int i=1;i<=m;i++) {
        scanf("%d%d",&umb[i].first,&umb[i].second);
    }
    sort(seg+1,seg+1+n);
    sort(umb+1,umb+1+m);
    for (int i=1;i<=m;i++) {
        if (id[umb[i].first] == 0)
        id[umb[i].first] = i;
    }

    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            dp[i][j] = INF;

    dp[0][0] = 0;
    for (int i=0;i<a;i++) {
        for (int j=0;j<=m;j++) {
            if (j!=0 || rain[i+1]==0) // 
                dp[i+1][j] = min(dp[i+1][j], dp[i][j]+umb[j].second);
            if (j!=0 && rain[i+1]==0) // 
                dp[i+1][0] = min(dp[i+1][0], dp[i][j]);
            if (id[i]) // 
                dp[i+1][id[i]] = min(dp[i+1][id[i]], dp[i][j] + umb[id[i]].second);
        }
    }

    int ans=INF;
    for(int i=0;i<=m;i++) ans=min(ans,dp[a][i]);
    if (ans==INF) ans=-1;
    printf("%d\n", ans);
}