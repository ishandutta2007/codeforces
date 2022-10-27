#include <iostream>
using namespace std;
typedef long long LL;
const LL MOD = 998244353;
const int N = 1000+10;
int n, a[N], ok[N];
LL c[N][N], dp[N];

int main() {
    for(int i=0;i<N;i++) c[i][0]=1;
    for(int i=1;i<N;i++){
        for(int j=1;j<=i;j++){
            c[i][j]=(c[i-1][j-1]+c[i-1][j])%MOD;
        }
    }
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        scanf("%d",&a[i]);
        if(a[i]>0 && a[i]<=n-i) {
            ok[i]=1;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<i;j++){
            if(a[j]<=i-j && a[j]>0) {
                dp[i]=dp[i] + (dp[j-1]+1)*c[i-j][a[j]]%MOD;
                dp[i]%=MOD;
            }
        }
    }
    cout<<dp[n]<<endl;
}