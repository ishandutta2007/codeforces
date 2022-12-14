#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1000010;
ll mod = 998244353;
ll Fact[N];
ll Power(ll a,ll b) {
    if (b==0)
        return 1;
    ll x = Power(a, b/2);
    x = (x*x)%mod;
    if (b%2)
        x=(x*a)%mod;
    return x;
}
ll Inv(ll x){
    return Power(x, mod-2);
}
ll C(ll n, ll m){
    return  (Fact[n] * Inv((Fact[n-m]*Fact[m])%mod))%mod;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    Fact[0] = 1;
    for (int i=1;i<N;i++)
        Fact[i] = (Fact[i-1]*i)%mod;
    ll n,k;
    cin>>n>>k;
    ll ret=0;
    for (int i=1;i<=n;i++){
        int num = n/i;
        if (num<k)break;
        ret+=C(num-1,k-1);
        ret%=mod;
    }
    cout<<ret<<endl;
}