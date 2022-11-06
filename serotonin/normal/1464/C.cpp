#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+5;

char s[sz];

ll fnc(char x) {
   return 1LL << (x - 'a');
}

int main() {
   int n;
   ll t;
   cin >> n >> t;
   scanf("%s", s);
   t -= fnc(s[n-1]);
   t += fnc(s[n-2]);
   n -= 2;

   for(int i=0; i<n; i++) t -= fnc(s[i]);

   if(t <= 0) t = -t;
   else {
      puts("No");
      return 0;
   }

   if(t & 1) {
      puts("No");
      return 0;
   }

   t >>= 1;

   int a[27] = {};
   for(int i=0; i<n; i++) a[s[i]-'a']++;


   for(int i=0; i<=25; i++) {
      if(t & (1LL << i)) {
         if(!a[i]) {
            puts("No");
            return 0;
         }
         a[i]--;
      }
      a[i+1] += a[i] >> 1;
   }

   puts("Yes");
}