#include <iostream>
#include <map>
using namespace std;
const int N = 300000 + 10;
typedef long long LL;
int q,n;
LL a[N],b[N];
map<int,LL> dp[N];

int main() {
    scanf("%d", &q);
    while(q--) {
        scanf("%d", &n);
        for(int i=1;i<=n;i++) {
            scanf("%lld%lld",&a[i],&b[i]);
            dp[i].clear();
        }
        dp[1][a[1]]=0, dp[1][a[1]+1]=b[1], dp[1][a[1]+2]=b[1]*2;
        for(int i=1;i<n;i++){
            for(auto p: dp[i]) {
                for(int h=a[i+1];h<=a[i+1]+2;h++) {
                    if(p.first != h) {
                        LL tmp = p.second + (h - a[i+1]) * b[i+1];
                        if(!dp[i+1].count(h)) {
                            dp[i+1][h] = tmp;
                        }else{
                            dp[i+1][h] = min(tmp, dp[i+1][h]);
                        }
                    }
                }
            }
        }
        LL res=1e18;
        for(int i=a[n];i<=a[n]+2;i++){
            if(dp[n].count(i)) res=min(res,dp[n][i]);
        }
        printf("%lld\n", res);
    }
}