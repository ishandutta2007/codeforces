#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=1e3+5;

ll a[sz][sz];

int main()
{
   int n;
   cin >> n;
   for(int i=0; i<n; i++) {
      for(int j=0; j<n; j++) {
         scanf("%lld", &a[i][j]);
      }
   }

   ll x=a[0][1]*a[0][2]/a[1][2];
   x=sqrt(x);
   printf("%lld", x);
   for(ll i=1; i<n; i++) {
      printf(" %lld", a[0][i]/x);
   }
}