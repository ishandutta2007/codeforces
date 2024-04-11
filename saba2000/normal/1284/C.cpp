#include<bits/stdc++.h>
#define ll long long
using namespace std;
long long f[1000009];
main(){
    ll n,m;
    cin>> n>> m;
    long long ans = 0;
    f[0] = 1;
    for(ll i = 1; i <= n; i++)
        f[i] = f[i-1]*i%m;
    for(ll l = 1; l <= n; l++){
        ans = (ans + f[l] * f[n - l] % m *(n - l +1) % m * (n - l +1) )% m;
    }
    cout<<ans<<endl;
}