#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

const int N = 1e5 + 11;

bool good(ll n, ll k)
{
      ll kol=(n+1)/2;
      while (n>0)
      {
            kol-=min(k,n);
            n-=min(k,n);
            n-=n/10;
      }
      if (kol<=0) return true;
      return false;
}

int main()
{
      ll n;
      cin>>n;
      ll l=1,r=1e18;
      while (r-l>1)
      {
            ll mid=(l+r)/2;
            if (good(n,mid)) r=mid; else l=mid;
      }
      if (good(n,l)) cout<<l<<"\n"; else cout<<r<<"\n";
}