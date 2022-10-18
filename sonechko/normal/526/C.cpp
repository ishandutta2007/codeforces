#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define ll long long

const int N = 20000 + 11;


ll c,h1,h2,w1,w2;

ll get1(ll x)
{
    ll y=(c-w1*x)/w2;
    return x*h1+y*h2;
}

ll get2(ll x)
{
    ll y=(c-w2*x)/w1;
    return x*h2+y*h1;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>c>>h1>>h2>>w1>>w2;
    ll ans=0;
    if (w1>sqrt(c))
    {
        for (int p=0; p<=c/w1; p++)
            ans=max(ans,get1(p));
    } else
    if (w2>sqrt(c))
    {
        for (int p=0; p<=c/w2; p++)
            ans=max(ans,get2(p));
    } else
    {
        int d=c/w1;
        for (int p=d; p>=max(0,d-1000000); p--)
            ans=max(ans,get1(p));
        d=c/w2;
        for (int p=d; p>=max(0,d-1000000); p--)
            ans=max(ans,get2(p));
    }
    cout<<ans<<"\n";
}