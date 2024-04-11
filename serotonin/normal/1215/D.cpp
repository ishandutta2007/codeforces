#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=3e5+5;

char s[sz];
int a[sz];

int main()
{
   int n;
   scanf("%d %s", &n, s);

   int l=0, r=0, ls=0, rs=0;
   for(int i=0; i<n; i++) {
      if(s[i]=='?') {
         if(i<n/2) l++;
         else r++;
      }
      else {
         if(i<n/2) ls+=s[i]-'0';
         else rs+=s[i]-'0';
      }
   }

   if(l<r) {
      int b=(r-l)/2;
      if(rs+9*b==ls) puts("Bicarp");
      else puts("Monocarp");
   }
   else {
      int b=(l-r)/2;
      if(ls+9*b==rs) puts("Bicarp");
      else puts("Monocarp");
   }
}