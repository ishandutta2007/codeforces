#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e5+5;

char s[sz];

void solve() {
   int n;
   scanf("%d", &n);
   scanf("%s", s);

   if(n > 1 and s[0] == s[1]) {
      printf("%c%c\n", s[0], s[1]);
      return;
   }

   for(int i=1; i<n; i++) {
      if(s[i] > s[i-1]) {
         for(int j=0; j<i; j++) printf("%c", s[j]);
         reverse(s, s+i);
         for(int j=0; j<i; j++) printf("%c", s[j]);
         puts("");
         return;
      }
   }
   printf("%s", s);
   reverse(s, s+n);
   puts(s);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}