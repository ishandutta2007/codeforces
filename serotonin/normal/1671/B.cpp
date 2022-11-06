#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e6+7;

int a[sz];

void solve() {
   int n;
   scanf("%d", &n);
   for(int i=0; i<n; i++) scanf("%d", &a[i]);

   for(int j=-1; j<=1; j++) {
      int b = a[0] + j;
      bool yes = 1;
      for(int i=0; i<n; i++, b++) {
         if(abs(a[i] - b) > 1) yes = 0;
      }
      if(yes) {
         puts("YES");
         return;
      }
   }
   puts("NO");
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}