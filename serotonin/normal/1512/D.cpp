#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 4e5+7;

int a[sz];

void solve() {
   int n;
   scanf("%d", &n);
   n += 2;
   for(int i=0; i<n; i++) scanf("%d", &a[i]);
   sort(a, a+n);

   ll sum = 0;
   for(int i=0; i<n; i++) sum += a[i];

   for(int i=0; i<n; i++) {
      ll now = sum - a[i];
      if(i < n - 1) {
         if(now == a[n - 1] * 2) {
            for(int j=0; j<n; j++) {
               if(i == j or j == n - 1) continue;
               printf("%d ", a[j]);
            }
            puts("");
            return;
         }
      }
      else {
         if(now == a[n - 2] * 2) {
            for(int j=0; j<n; j++) {
               if(i == j or j == n - 2) continue;
               printf("%d ", a[j]);
            }
            puts("");
            return;
         }
      }
   }
   puts("-1");
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}