#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=3e5+5;

int a[sz],d[sz],e[sz];

int main()
{
   ll n;
   cin >> n;
   for(int i=1; i<=n; i++) scanf("%d", &a[i]);

   int x=0, y, f=0;
   ll ans=0;
   for(int i=n; i; i--) {
      y=n-i-x;
      if(a[i]<0) {
         if(f) ans+=x+1;
         else ans+=y+1;
      }
      else {
         if(f) ans+=y;
         else ans+=x;
      }

      if(f) x++;
      if(a[i]<0) f^=1;
   }

   printf("%lld %lld\n", ans, n*(n+1)/2-ans);
}