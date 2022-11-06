#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e6+7;

int a[sz];

void solve() {
   int n, x, sum = 0;
   scanf("%d %d", &n, &x);
   for(int i=0; i<n; i++) scanf("%d", &a[i]), sum += a[i];
   if(sum == x) {
      puts("NO");
      return;
   }
   sort(a, a+n);
   sum = 0;
   for(int i=0; i<n; i++) {
      sum += a[i];
      if(sum == x) {
         swap(a[i], a[n-1]);
         break;
      }
   }
   puts("YES");
   for(int i=0; i<n; i++) printf("%d ", a[i]);
   puts("");
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}