#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1e6+5;

char s[sz];
bool a[sz], ra[sz];

void solve() {
   scanf("%s", s);
   int n = strlen(s);
   int x;
   scanf("%d", &x);
   for(int i=0; i<n; i++) a[i] = 1;
   for(int i=0; i<n; i++) {
      if(s[i] == '0') {
         if(i-x >= 0) a[i-x] = 0;
         if(i+x < n) a[i+x] = 0;
      }
   }

   for(int i=0; i<n; i++) {
      if(i-x >= 0 && a[i-x]) ra[i] = 1;
      else if(i+x < n && a[i+x]) ra[i] = 1;
      else ra[i] = 0;
   }

   for(int i=0; i<n; i++) {
      if(s[i] - '0' != ra[i]) {
         puts("-1");
         return;
      }
   }

   for(int i=0; i<n; i++) {
      if(a[i]) printf("1");
      else printf("0");
   }
   puts("");
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}