#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+5;

int a[sz], c[sz];
char s[sz];

void solve() {
   int n;
   scanf("%d", &n);
   for(int i=1; i<=n; i++) c[i] = 0, s[i-1] = '0';
   for(int i=1; i<=n; i++) scanf("%d", &a[i]), c[a[i]]++;
   for(int i=1, l=1, r=n; i<=n; i++) {
      if(c[i]) {
         if(i == 1) {
            s[n-i] = '1';
            continue;
         }
         if(c[i-1] == 1 && (a[l] == i-1 || a[r] == i-1)) {
            if(a[l] == i-1) l++;
            else r--;
            s[n-i] = '1';
         }
         else break;
      }
      else break;
   }

   bool x = 1;
   for(int i=1; i<=n; i++) if(c[i] > 1) x = 0;
   if(x) s[0] = '1';

   s[n] = 0;
   printf("%s\n", s);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}