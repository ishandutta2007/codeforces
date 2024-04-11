#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 5000 + 11;

map<ll,ll> mt;
ll ks[N];
ll n;

ll get(ll x)
{
    if (x==0) return 0;
    if (x>n) return 0;
    if (x%2==1) return get(x*2ll)+1ll; else
    {
        ///cout<<"! "<<x<<endl;
        ll ans=2;
        if (x==n) ans--;
        ll t=1;
        ll y=x,mx=0;
        while (y*2<=n)
        {
            y*=2;
            t*=2;
            mx+=t;
            ll p=n-y;
            p=min(p,mx);
            ///cout<<y<<" "<<p<<" "<<(p/2ll+1)*2ll<<endl;
            ans+=2ll*(p/2ll+1);
            ll c=y+(p/2ll)*2ll;
            if (c==n) ans--;
        }
        return ans;
    }
}

ll gett(ll x)
{
    if (x>n) return 0;
    if (mt.find(x)!=mt.end()) return mt[x];
    if (x%2==1) return mt[x]=gett(x*2ll)+1ll; else
        return mt[x]=gett(x*2ll)+gett(x+1ll)+1ll;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll k;
    cin>>n>>k;
    ll l=0,r=(n-1)/2,ans=0;
    while (r-l>1)
    {
        ll mid=(l+r)/2;
        mid=mid*2+1;
        if (get(mid)>=k) l=(l+r)/2; else r=(l+r)/2;
    }
    if (get(l*2+1)>=k) ans=l*2+1;
    if (get(r*2+1)>=k) ans=r*2+1;
    l=1;
    r=n/2;
    while (r-l>1)
    {
        ll mid=(l+r)/2;
        mid=mid*2;
        if (get(mid)>=k) l=(l+r)/2; else r=(l+r)/2;
    }
    if (get(l*2)>=k) ans=max(ans,l*2);
    if (get(r*2)>=k) ans=max(ans,r*2);
    cout<<ans<<endl;
}
/**

if (x%2==0) s[x]=s[x*2]+1
    else s[x]=s[x+1]+s[x*2]+1=s[x*2]+s[x*2+2]+2

a[x]=a[x*2]+a[x*2+2]+2

             x           0
     x*2        x*2+2
   x*4  x*4+2  x*4+4  x*4+6
x*8 x*8+2 x*8+4 x*8+6 x*8+8 x*8+10 x*8+12 x*8+14
x*5+6<x*8

2
4


2 6 14
 4 8
1 3

10    n=30
10 (2)
20 (2)    22 (2)


l .. r   n

1 1 1 1 1 1 1 1

l .. l*2

try l

0 1 2 3 4
1 3 5 7 9

       2
   2*2=4   2*2+2=6
 2*4=8 2*4+2=10 2*4+4=12 2*4+6=14

**/