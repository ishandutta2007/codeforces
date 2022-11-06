#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=2e5+5;

ll b[sz];
vector <ll> a[69];

int main()
{
   ll n;
   scanf("%lld", &n);
   for(ll i=1; i<=n; i++) scanf("%lld", &b[i]);

   for(ll i=1; i<=n; i++) {
      ll c=0, x=b[i];
      while(!(x&1LL)) {
         x>>=1LL;
         c++;
      }
      a[c].push_back(b[i]);
   }

   ll big=0,who;
   for(ll i=0; i<69; i++) {
      ll z=a[i].size();
      if(z>big) {
         big=z;
         who=i;
      }
   }

   printf("%lld\n", n-big);
   for(ll i=0; i<69; i++) {
      if(i==who) continue;
      for(ll j=0; j<a[i].size(); j++) {
         printf("%lld ", a[i][j]);
      }
   }
}