#include <iostream>
#include <cstring>
using namespace std;
const int N=500+10;
typedef long long LL;
const LL MOD = 1e9 + 7;
int n;

LL dp[N][N],f[502],a[N];
LL solve(int l,int r) {
    if(dp[l][r]!=-1)return dp[l][r];
    if(l>=r)return 1;
    if(l+1==r)return 1;

    dp[l][r]=solve(l+1,r);
    for(int i=l+2;i<=r;i++) {
        if(a[i]>a[l+1]) {
            // [l+1,i-1], first sub-tree
            // [i,r], others sub-tree
            dp[l][r] += solve(l+1,i-1) * solve(i-1,r) % MOD; 
            dp[l][r] %= MOD;
        }
    }
    return dp[l][r];
}

int main() {
    memset(dp,-1,sizeof(dp));
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    cout<<solve(1,n)<<endl;
}