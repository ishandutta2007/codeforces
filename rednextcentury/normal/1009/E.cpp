#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll P[1000005];
ll mod = 998244353;
ll a[2000000];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    P[0]=1;
    for (int i=1;i<=n;i++){
        P[i]=(P[i-1]*2)%mod;
        cin>>a[i];
    }
    ll cur = a[1];
    ll ret=(cur*P[n-1])%mod;
    for (int i=2;i<=n;i++){
        cur = (cur*2 - a[i-1] + a[i])%mod;
        cur+=mod;
        cur%=mod;
        ret+=(cur*P[n-i])%mod;
        ret%=mod;
    }
    cout<<ret<<endl;
}