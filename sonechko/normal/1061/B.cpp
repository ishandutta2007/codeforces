#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int N = 2e5 + 11;

ll a[N];

int main()
{
      int n,m;
      cin>>n>>m;
      for (int i=1; i<=n; i++)
      cin>>a[i];
      sort(a+1,a+n+1);
      ll ans=0;
      ll t=a[n];
      for (int i=n; i>=1; i--)
      {
            ll kol=1;
            t--;
            while (a[i-1]<t)
            {
                  kol++;
                  t--;
            }
            ans+=a[i]-kol;
      }
      cout<<ans<<endl;
}