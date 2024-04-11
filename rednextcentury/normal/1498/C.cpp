#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n;
ll mod = 1000000007;
ll dp[2000][2000][2];
ll DP(int age, int pos, int dir){
    if (pos <= 0 || pos>n) return 1;
    if (age == 1) return 1;
    if (dp[age][pos][(dir+1)/2] != -1)
        return dp[age][pos][(dir+1)/2];
    dp[age][pos][(dir+1)/2] = (DP(age, pos+dir, dir) + DP(age-1, pos-dir, -dir))%mod;
    return dp[age][pos][(dir+1)/2];
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int k;
        cin>>n>>k;
        for (int i=0;i<=n;i++) for (int j=0;j<=k;j++) for (int p=0;p<=1;p++) dp[j][i][p] = -1;
        cout<<DP(k, 1, 1)<<endl;
    }
}