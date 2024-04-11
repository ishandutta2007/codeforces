#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+5;

char s[sz];

void solve()
{
   int n;
   cin >> n;
   scanf("%s", s);

   int one = n, zero = -1;
   for(int i=0; i<n; i++) {
      if(s[i] == '1') {
         one = i;
         break;
      }
   }
   for(int i=n-1; i>=0; i--) {
      if(s[i] == '0') {
         zero = i;
         break;
      }
   }

   if(one > zero) puts(s);
   else {
      for(int i=0; i<one; i++) printf("%c", s[i]);
      for(int i=zero; i<n; i++) printf("%c", s[i]);
      puts("");
   }
}

int main()
{
   int t;
   cin >> t;
   while(t--) solve();
}