#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll mod = 1000000007;
ll dp[2006];
pair<int,int> a[2006];
ll F[1000000];
ll iF[1000000];

ll Power(ll a,ll b) {
    if (b==0)return 1;
    ll x = Power(a,b/2);
    x = (x*x)%mod;
    if (b%2)x=(x*a)%mod;
    return x;
}
ll inv(ll x){return Power(x,mod-2);}
ll C(int x,int y) {
    return (F[x]*((iF[x-y]*iF[y])%mod))%mod;
}
ll countPaths(int x1,int y1,int x2,int y2){
    if (x1>x2 || y1>y2)return 0;
    return C(x2-x1+y2-y1,x2-x1);
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    F[0]=1;
    iF[0]=1;
    for (int i=1;i<=600000;i++){
        F[i]=(F[i-1]*i)%mod;
        iF[i]=inv(F[i]);
    }
    int h,w,n;
    cin>>h>>w>>n;
    for (int i=1;i<=n;i++) {
        cin>>a[i].first>>a[i].second;
    }
    sort(a+1,a+n+1);
    a[++n]={h,w};

    for (int i=1;i<=n;i++) {
        dp[i]=countPaths(1,1,a[i].first,a[i].second);
        for (int j=1;j<i;j++) {
            dp[i] -= (dp[j]*countPaths(a[j].first,a[j].second,a[i].first,a[i].second))%mod;
            dp[i] = (dp[i]+mod)%mod;
        }
    }
    cout<<dp[n]<<endl;
}