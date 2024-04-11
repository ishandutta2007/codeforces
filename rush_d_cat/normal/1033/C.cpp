#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 200000 + 10;
int dp[N],n,a[N],p[N];

int dfs(int i) {
    if(dp[i]!=-1) return dp[i];
    for(int j=i+a[i];j<=n;j+=a[i]) {
        if(a[j]>a[i]) {
            if(dfs(j)==0) return dp[i]=1;
        }
    }
    for(int j=i-a[i];j>=1;j-=a[i]) {
        if(a[j]>a[i]) {
            if(dfs(j)==0) return dp[i]=1;
        }
    }
    return dp[i]=0;
}
int main() {
    memset(dp,-1,sizeof(dp));
    scanf("%d",&n); 
    for(int i=1;i<=n;i++) {
        scanf("%d",&a[i]); p[a[i]]=i;
    }
    for(int i=1;i<=n;i++) {
        dfs(p[a[i]]);
    }
    for(int i=1;i<=n;i++) {
        printf("%c", dfs(i)?'A':'B');
    }
    printf("\n");

}