#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+7;

int a[sz], lhs[sz], rhs[sz];
char s[sz];

void solve() {
   int n;
   scanf("%d", &n);
   for(int i=0; i<n; i++) scanf("%d", &a[i]);
   scanf("%s", s);

   for(int i=1; i<=n; i++) lhs[i] = rhs[i] = 0;

   for(int i=0; i<n; i++) {
      if(s[i] == 'B') {
         a[i] = min(a[i], n);
         if(a[i] < 1) {
            puts("NO");
            return;
         }
         lhs[a[i]]++;
      }
      else {
         a[i] = max(a[i], 1);
         if(a[i] > n) {
            puts("NO");
            return;
         }
         rhs[a[i]]++;
      }
   }

   for(int i=1, j=1; i<=n; i++) {
      while(lhs[i] > 0) {
         if(j > i) {
            puts("NO");
            return;
         }
         lhs[i]--;
         j++;
      }
   }

   for(int i=n, j=n; i; i--) {
      while(rhs[i] > 0) {
         if(j < i) {
            puts("NO");
            return;
         }
         rhs[i]--;
         j--;
      }
   }

   puts("YES");
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}