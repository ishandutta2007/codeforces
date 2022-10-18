#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ff first
#define ss second
#define ull unsigned long long
#define mp make_pair
#define ll long long
const int N = 4e5 + 11;
const int MOD = 1e9 + 9;

ll st(ll x, ll y)
{
          if (y==0) return 1;
          if (y%2==1) return (x*st(x,y-1))%MOD;
          ll p=st(x,y/2);
          return (p*p)%MOD;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n,a,b,k;
    cin>>n>>a>>b>>k;
    ll xx=0;
    for (int i=0; i<k; i++)
    {
              ll d=st(a,n-i);
              ll dd=st(b,i);
              char ch;
              cin>>ch;
              d=(d*dd)%MOD;
              if (ch=='+') xx=(xx+d)%MOD; else
              xx=(xx+MOD-d)%MOD;
    }
    ll q=st(b,k);
    ll cc=st(a,k);
    q=(q*st(cc,MOD-2))%MOD;
    if (q==1)
    {
              ll res=(xx*((n+1)/k))%MOD;
              cout<<res<<endl;
              return 0;
    }
    ll ans=(xx*(st(q,(n+1)/k+MOD-1)+MOD-1))%MOD;
    ans=(ans*st((q+MOD-1)%MOD,MOD-2))%MOD;
    cout<<ans<<endl;
}