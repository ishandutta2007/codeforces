#include<bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long
ll ans(ll k1, ll k2, ll k3)
{
    ll nsd1=__gcd(k1,k2);
    ll nsk1=k1*k2/nsd1;
    ll nsd2=__gcd(nsk1,k3);
    ll nsk2=nsk1*k3/nsd2;
    return nsk2;
}
int main()
{
    int n;
    cin>>n;
    if (n==1) cout<<1<<endl; else
    if (n%2==1) cout<<ans(n,n-1,n-2)<<endl; else
    if (n==2) cout<<2<<endl; else
    cout<<max(ans(n,n-1,n-2),max(ans(n,n-1,n-3),ans(n-1,n-2,n-3)))<<endl;
}