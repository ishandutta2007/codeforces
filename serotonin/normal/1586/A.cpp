#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e4+7;

int a[sz];
bool ok[sz];

void solve() {
   int n;
   scanf("%d", &n);
   int sum = 0;
   for(int i=0; i<n; i++) scanf("%d", &a[i]), sum += a[i];

   if(ok[sum]) {
      printf("%d\n", n);
      for(int i=0; i<n; i++) printf("%d ", i+1); puts("");
      return;
   }

   for(int j=0; j<n; j++) if(ok[sum - a[j]]) {
      printf("%d\n", n - 1);
      for(int i=0; i<n; i++) if(i ^ j) printf("%d ", i+1); puts("");
      return;
   }

   for(int j=0; j<n; j++) {
      for(int k=j+1; k<n; k++) {
         if(ok[sum - a[k] - a[j]]) {
            printf("%d\n", n - 2);
            for(int i=0; i<n; i++) if(i ^ j and i ^ k) printf("%d ", i+1); puts("");
            return;
         }
      }
   }
}

int main() {
   for(int i=2; i<sz; i++) {
      if(ok[i]) continue;
      for(int j=i<<1; j<sz; j+=i) ok[j] = 1;
   }

   int t;
   cin >> t;
   while(t--) solve();
}