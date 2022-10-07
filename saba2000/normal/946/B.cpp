#include<bits/stdc++.h>
#define ll long long
using namespace std;
pair<ll, ll> f(ll n, ll m)
{
    if(n == 0 || m == 0) return {n,m};
    if (n >= 2*m) return f(n % (2*m), m);
    if (m >= 2*n) return f(n, m % (2*n));
    return {n,m};
}
main()
{
    ll n,m;
    cin >> n >> m;
    pair<ll , ll> ans = f(n, m);
    cout << ans.first <<" "<< ans.second << endl;

}