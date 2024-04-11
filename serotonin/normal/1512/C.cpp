#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 4e5+7;

char s[sz];

void solve() {
   int a, b, n;
   scanf("%d %d %s", &a, &b, s);
   n = a + b;

   if((a & 1) and (b & 1)) {
      puts("-1");
      return;
   }

   if(a & 1) {
      if(s[n / 2] == '1') {
         puts("-1");
         return;
      }
      a--;
      s[n / 2] = '0';
   }

   if(b & 1) {
      if(s[n / 2] == '0') {
         puts("-1");
         return;
      }
      b--;
      s[n / 2] = '1';
   }

   for(int i=0, j=n-1; i<j; i++, j--) {
      if(s[i] == '?' and s[j] == '?') continue;
      if(s[i] == '?') s[i] = s[j];
      else if(s[j] == '?') s[j] = s[i];
      if(s[i] != s[j]) {
         puts("-1");
         return;
      }
      if(s[i] == '0') a -= 2;
      else b -= 2;
   }

   if(a < 0 or b < 0) {
      puts("-1");
      return;
   }

   for(int i=0, j=n-1; i<j; i++, j--) {
      if(s[i] == '?') {
         if(a) s[i] = s[j] = '0', a -= 2;
         else s[i] = s[j] = '1', b -= 2;
      }
   }
   puts(s);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}