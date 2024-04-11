#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=1e6+5;

int main()
{
   int l,r;
   cin >> l >> r;
   for(int i=l; i<=r; i++) {
      int n=i;

      bool yes=1;
      int a[10]={0};
      while(n) {
         if(a[n%10]) yes=0;
         a[n%10]=1;
         n/=10;
      }

      if(yes) {
         printf("%d\n", i);
         return 0;
      }
   }
   puts("-1");
}