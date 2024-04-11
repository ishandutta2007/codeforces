#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;
const int N = 1000000 + 10;
int n,k,l;
int a[N],s[N]; 
LL g[N];
double f[N],dp[N];
char str[N];
LL solve(double cost) {
    for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
    //printf("cost = %.5f\n", cost);
    for(int i=1;i<=n;i++){
        int x=max(i-l,0);
        dp[i]=f[x]+(s[i]-s[x])-cost;
        if(dp[i]<f[i-1]){
            f[i]=f[i-1]; g[i]=g[i-1];
        } else {
            f[i]=dp[i]; g[i]=g[x]+1;
        }
       // printf("i=%d, x=%d, dp=%.5f, f=%.5f, g=%d\n", i,x,dp[i],f[i],g[i]);
    }
    return g[n]<=k?1:0;
}
LL solve() {
    double lef=0,rig=1e9;
    for(int i=1;i<=100;i++){
        double mid=(lef+rig)/2;
        if(solve(mid)){
            rig=mid;
        }else{
            lef=mid;
        }
    }
    //printf("A = %lld\n", (LL)(f[n] + k * lef + 0.1));
    LL ans = (LL)(f[n] + k * lef + 0.1);
    for (int i=1;i<=n;i++)if(a[i]==0)ans++; 
    return ans;
} 
int up(char c){
    return c>='A'&&c<='Z';
}
int main() {
    scanf("%d%d%d%s",&n,&k,&l,str+1);
    if(1LL*k*l>=n)return !printf("0\n");
    LL ans=1e9;
    for(int i=1;i<=n;i++)a[i]=!up(str[i]);
    ans=min(ans,n-solve());
    for(int i=1;i<=n;i++)a[i]=1-a[i];
    ans=min(ans,n-solve());
    cout<<ans<<endl;
}