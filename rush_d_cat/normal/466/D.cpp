#include <iostream>
using namespace std;
typedef long long LL;
const int N = 2002;
const int MOD = 1e9 + 7;
int n,h;
int a[N],l[N],r[N];
int dp[N];
int main() {
    scanf("%d%d",&n,&h);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    dp[1] = 1;
    if(a[1]+1 < h || a[1] > h || a[n] + 1 < h || a[n] > h) return !printf("0\n");
    for(int i=2;i<=n;i++){
        int need = h-a[i] ;
        if (need < 0) return !printf("0\n");
        int pre = h-a[i-1];

        if(pre == need) {
            dp[i] = 1LL*(pre+1)*dp[i-1]%MOD;
        } else if(pre + 1 == need) {
            dp[i] = dp[i-1];
        } else if(need+1 == pre) {
            dp[i] = 1LL*pre*dp[i-1]%MOD;
        } else {
            dp[i]=0;
        }
    }   
    printf("%d\n", dp[n]);
}