#include <iostream>
#include <cstring>
using namespace std;
typedef long long LL;
const int N = 60;
int n,k; 
LL a[N],sum[N][N],dp[N][N];
LL s;
bool solve(int bit) {
    LL mask = s | (1LL << bit);
    memset(dp,0,sizeof(dp));
    dp[0][0]=1;
    for(int i=0;i<n;i++)
        for(int j=0;j<k;j++) {
            if (dp[i][j]==0) continue;
            for(int x=i+1;x<=n;x++) {
                if ((sum[i+1][x]&mask)==mask) {
                    dp[x][j+1]=1;
                }
            }
        }
    return dp[n][k]?1:0;
}

int main() {
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) {
        scanf("%lld",&a[i]);
    }
    for(int i=1;i<=n;i++) {
        sum[i][i]=a[i];
        for(int j=i+1;j<=n;j++) {
            sum[i][j]=(sum[i][j-1]+a[j]);
        }
    }
    //solve(6); return 0;
    for(int i=55;i>=0;i--) {
        if (solve(i)) {
            s |= (1LL<<i);
        }
    }
    cout<<s<<endl;
}