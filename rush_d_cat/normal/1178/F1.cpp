#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;
typedef long long LL;
const int N = 500 + 10;
const LL MOD=998244353;
int n,m,a[N];
LL dp[N][N],g[N][N];

LL solve(int l,int r){
    if(l==r) return dp[l][r]=1;
    if(l>r) return 1;
    if(dp[l][r]!=-1) return dp[l][r];
    //printf("l=%d,r=%d\n", l,r);
    int mn=N,mid=0;
    for(int i=l;i<=r;i++){
        if(a[i]<=mn) {
            mn=a[i]; mid=i;
        }
    }
    for(int mid=l;mid<r;mid++){
        solve(l,mid); solve(mid+1,r);
    }

    dp[l][r] = g[l][mid-1]*g[mid+1][r]%MOD;
    for(int i=l-1;i<=r;i++) {
        g[l][r]=g[l][r]+dp[l][i]*dp[i+1][r]%MOD;
        g[l][r]%=MOD;
    }
    //printf("[%d, %d], dp=%d, g=%d\n", l,r,dp[l][r],g[l][r]);
    return dp[l][r];
}

int main() {
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    memset(dp,-1,sizeof(dp));
    for(int i=1;i<=n+1;i++) {
        dp[i][i-1]=1,g[i][i-1]=1,g[i][i]=2,dp[i][i]=1;
    }
    cout<<solve(1,n)<<endl;
}