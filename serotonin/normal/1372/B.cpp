#include <bits/stdc++.h>
using namespace std;
const int sz = 5e4+5;

int a[sz];

void solve() {
   int n;
   scanf("%d", &n);
   for(int i=2; i*i<=n; i++) {
      if(n % i == 0) {
         int j = n / i;
         printf("%d %d\n", j, n - j);
         return;
      }
   }
   printf("1 %d\n", n-1);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}