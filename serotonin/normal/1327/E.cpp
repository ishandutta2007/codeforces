#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll sz=2e5+5, mod=998244353;

ll a[sz], pw[sz];

int main()
{
    ll n;
    cin >> n;
    pw[0]=1;
    for(ll i=1, j=0, k=0; i<=n; i++) {
        pw[i]=(pw[i-1]*10)%mod;
        a[i]=(((i*pw[i])%mod)-k)%mod;
        if(a[i]<0) a[i]+=mod;
        j+=a[i], j%=mod;
        k+=(a[i]+j)%mod, k%=mod;
    }
    for(ll i=n; i; i--) printf("%lld ", a[i]);
}