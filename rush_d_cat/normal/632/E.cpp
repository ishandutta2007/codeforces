#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
typedef __int64 ll;
const ll MAX=1000000+3;
int dp[MAX],a[1000+2];
int n,k;
int main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    n=unique(a+1,a+n+1)-(a+1);
    int tmp=a[1];
    for(int i=1;i<=n;i++) a[i]-=tmp;
    for(int i=1;i<=MAX;i++) dp[i]=k+1;
    for(int i=2;i<=n;i++){
        for(int j=a[i];j<=k*a[i];j++){
            dp[j]=min(dp[j],dp[j-a[i]]+1);
        }
    }
    for(int i=0;i<=k*a[n];i++) if(dp[i]<=k) printf("%d ",k*tmp+i);
    return 0;
}