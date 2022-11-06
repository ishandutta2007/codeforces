#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=3e5+5;

int a[sz];

int main()
{
   int a1,a2,k1,k2,n;
   cin >> a1 >> a2 >> k1 >> k2 >> n;

   int smol,big;

   int x=(k1-1)*a1+(k2-1)*a2;
   if(x>=n) smol=0;
   else smol=n-x;

   if(k1<k2) {
      big=min(a1,n/k1);
      n-=big*k1;
      big+=min(a2,n/k2);
   }
   else {
      big=min(a2,n/k2);
      n-=big*k2;
      big+=min(a1,n/k1);
   }

   printf("%d %d\n", smol, big);
}