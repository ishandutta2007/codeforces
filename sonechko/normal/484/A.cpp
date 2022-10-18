#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define ll long long
const int N = 2e5 + 11;
ll st(ll t)
{
    ll d=1;
    for (int i=1; i<=t; i++)
        d*=2;
    return d;
}
ll aa(ll k)
{
    for (int i=0; i<=100; i++)
        if (st(i)>k) return i-1;
}
ll f(ll l, ll r)
{
    if (l==r) return l;
    ll p=aa(r);
    ll d=st(p);
    if (d<=l) return f(l-d,r-d)+d;
    if (st(p+1)-1<=r) return st(p+1)-1;
    return d-1;
}

int main()
{
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        ll l,r;
        cin>>l>>r;
        cout<<f(l,r)<<"\n";
    }
}