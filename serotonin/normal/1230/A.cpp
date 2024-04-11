#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=3e5+5;

int main()
{
   int a[5],tot=0;
   for(int i=0; i<4; i++) cin >> a[i], tot+=a[i];

   bool yes=0;
   for(int i=0; i<4; i++) {
      int x=tot-a[i];
      if(a[i]==x) yes=1;
      else {
         for(int j=0; j<4; j++) {
            if(i==j) continue;
            if(a[i]+a[j]==x-a[j]) yes=1;
         }
      }
   }

   if(yes) puts("YES");
   else puts("NO");
}