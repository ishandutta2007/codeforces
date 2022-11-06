#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e6+5;

int a[sz];

void solve() {
   int l, n;
   scanf("%d %d", &l, &n); n++;
   for(int i=0; i<n; i++) scanf("%d", &a[i]);

   ll b[20] = {}, tot = 0;
   for(int i=0; i<n; i++) {
      tot += a[i];
      for(int j=0; j<20; j++) if(i & 1 << j) b[j]++;
   }

   for(int i=0; i<n; i++) {
      ll sum = 0;
      for(int j=0; j<20; j++) {
         if(a[i] & 1 << j) {
            sum += (1 << j) * (n - b[j]);
         }
         else {
            sum += (1 << j) * b[j];
         }
      }
      if(sum == tot) {
         printf("%d\n", a[i]);
         return;
      }
   }
   puts("-1");
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}