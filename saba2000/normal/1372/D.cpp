#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[400009],s[400009];
main(){
    ios_base::sync_with_stdio(false);
    ll n;
    cin >> n;
    for(ll i = 1; i <= n; i++)
        cin >> a[i],
        a[i+n] = a[i];
    s[1] = a[1];
    for(ll i = 2; i <= 2*n; i++)
        s[i] = a[i] + s[i-2];
    ll ans = s[n];
    for(ll i = n+1; i <= 2*n; i++)
        ans = max(ans, s[i] -s[i-n-1]);
    cout << ans<<endl;

}