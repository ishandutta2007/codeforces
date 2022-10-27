#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long LL;
const int N=100000+10;
int dp[16][3000];
int n,a[N];
int main(){
    scanf("%d",&n);
    int sum=0;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        sum+=a[i];
    }
    dp[0][0]=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<=2700;j++){
            if(dp[i][j])
                dp[i+1][j+a[i+1]]=1, dp[i+1][j]=1;
        }
    }
    bool ok=0;
    for(int i=0;i<=2700;i++){
        if(dp[n][i] && (i-(sum-i))%360==0) ok=1;
    }
    printf("%s\n", ok?"YES":"NO");
}