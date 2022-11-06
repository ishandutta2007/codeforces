#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 4e5+7;

int a[sz];

void solve() {
   int n, c[10] = {};
   scanf("%d", &n);
   for(int i=0; i<n; i++) scanf("%d", &a[i]), c[a[i] % 10]++;

   for(int i=0; i<10; i++) {
      if(!c[i]) continue;
      c[i]--;
      for(int j=0; j<10; j++) {
         if(!c[j]) continue;
         c[j]--;
         for(int k=0; k<10; k++) {
            if(!c[k]) continue;
            int sum = i + j + k;
            sum %= 10;
            if(sum == 3) {
               puts("YES");
               return;
            }
         }
         c[j]++;
      }
      c[i]++;
   }
   puts("NO");
}

int main() {
   int t; cin >> t;
   while(t--) solve();
}