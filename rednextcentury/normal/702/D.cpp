# include <bits/stdc++.h>
using namespace std;
#define ll long long
ll d,k,a,b,t;
ll R;
ll check(ll m)
{
    ll cost = m*a*k+(R-m*k)*b+t*(max(0LL,m-1));
    return cost;
}
int main()
{
    cin>>d>>k>>a>>b>>t;
    ll l = 0;
    ll r = (d-d%k)/k;
    R = d-d%k;
    ll ret = 1e18;
    while(l<r)
    {
        ll m1 = (l+r)/2;
        ll m2 = m1+1;
        ll X = check(m1);
        ll Y = check(m2);
        if (Y<X)
        {
            ret=min(ret,Y);
            l = m2+1;
        }
        else
        {
            ret=min(ret,X);
            r = m2-1;
        }
    }
    for (ll i = l; i<=r; i++)
        ret=min(ret,check(i));
    if (d<=k)
    {
        cout<<a*d<<endl;
        return 0;
    }
    cout<<ret+min((d%k)*a+t,(d%k)*b)<<endl;
}