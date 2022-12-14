#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[1000000];
int dp[1000000][2];
int n,k;
bool check1(int mid){
    dp[0][1]=-100000;
    for (int i=1;i<=n;i++){
        dp[i][0] = dp[i-1][0];
        dp[i][1] = dp[i-1][1];
        if (a[i]<=mid)
            dp[i][0] = max(dp[i-1][1]+1, dp[i][0]);
        dp[i][1]=max(dp[i-1][0]+1, dp[i][1]);
    }
    return max(dp[n][0],dp[n][1])>=k;
}
bool check2(int mid){
    dp[0][1]=-100000;
    for (int i=1;i<=n;i++){
        dp[i][0] = dp[i-1][0];
        dp[i][1] = dp[i-1][1];
        dp[i][0] = max(dp[i-1][1]+1, dp[i][0]);
        if (a[i]<=mid)
            dp[i][1]=max(dp[i-1][0]+1, dp[i][1]);
    }
    return max(dp[n][0],dp[n][1])>=k;
}
bool check(int mid){
    return check1(mid) || check2(mid);
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>k;
    int ret=1e9;
    for (int i=1;i<=n;i++) cin>>a[i];
    int l=1,r=1000000000;
    while(l<=r){
        int mid = (l+r)/2;
        if (check(mid)) ret=mid, r=mid-1;
        else l=mid+1;
    }
    cout<<ret<<endl;
}