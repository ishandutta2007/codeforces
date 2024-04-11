#include<bits/stdc++.h>
using namespace std;
#define ll long long
long long dp[501][501];
int a[501];
int b[501];
int n,k;
ll totalRed, totalBlue;
long long solve(){
    for (int red=0;red<k;red++) dp[0][red]=-1e15;
    dp[0][0]=0;
    for (int i=0;i<n;i++){
        for (int red=0;red<k;red++) dp[i+1][red]=-1e15;
        for (int red=0;red<k;red++){
            if (red>totalRed)continue;
            int blue = (totalBlue+totalRed-red)%k;
            if (blue>totalBlue)continue;
            for (int eRed=0;eRed<=min(k-1, a[i]);eRed++){
                int eBlue = (a[i]+b[i]-eRed)%k;
                if (eBlue>b[i])continue;
                int extra = (a[i]+b[i]-eRed)/k + (red+eRed)/k + (blue+eBlue)/k;
                dp[i+1][(red+eRed)%k] = max(dp[i+1][(red+eRed)%k], dp[i][red]+extra);
            }
        }
        totalRed+=a[i];
        totalBlue+=b[i];
    }
    ll ret=0;
    for (int i=0;i<k;i++) ret=max(ret, dp[n][i]);
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>k;
    for (int i=0;i<n;i++){
        cin>>a[i]>>b[i];
    }
    cout<<solve()<<endl;
}