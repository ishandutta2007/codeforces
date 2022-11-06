#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int sz = 2e6+5;

int a[sz], lhs[sz], rhs[sz];
bool black[sz];

int main() {
   int n;
   cin >> n;
   for(int i=1; i<=n; i++) scanf("%d", &a[i]);
   for(int i=1, j=0; i<=n; i++) {
      if(a[i] > a[i-1]) lhs[i] = ++j;
      else lhs[i] = j = 1;
   }
   for(int i=n, j=0; i; i--) {
      if(a[i] > a[i+1]) rhs[i] = ++j;
      else rhs[i] = j = 1;
   }
   int what = 0, cnt = 0, who = 0;
   for(int i=1; i<=n; i++) if(lhs[i] == rhs[i]) {
      int x = lhs[i];
      if(x > what) what = x, cnt = 1, who = i;
      else if(x == what) cnt++;
   }

   if(cnt == 1) {
      bool yes = 1;
      for(int i=1; i<=n; i++) if(i != who) {
         int x = max(lhs[i], rhs[i]);
         if(x >= what) yes = 0;
      }
      if(yes) {
         if(what & 1) yes = 1;
         else yes = 0;
      }
      if(yes) puts("1");
      else puts("0");
   }
   else puts("0");
}