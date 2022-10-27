#include <iostream>
using namespace std;
typedef long long LL;
const int N = 2002;
int n,k,a[N];
int dp[N];
bool check(LL x) {
    dp[0]=0; for(int i=1;i<=n;i++) dp[i]=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<i;j++){
            if(j==0 || (abs(a[i]-a[j]) + (i-j-1)) / (i-j) <= x)
                dp[i] = max(dp[j]+1,dp[i]);
        }
        //printf("dp[%d]=%d\n", i,dp[i]);
    }
    for(int i=1;i<=n;i++){
        if(dp[i] >= n-k) return 1;
    }
    return 0;
}
int main() {
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);

    LL lef=-1,rig=2e9;
    while(rig-lef>1){
        LL mid=(lef+rig)>>1;
        if(check(mid)) 
            rig=mid; 
        else 
            lef=mid;
    }
    printf("%lld\n", rig);
}