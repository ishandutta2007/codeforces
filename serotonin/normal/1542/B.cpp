#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e6+7;

void solve() {
   int n, a, b;
   scanf("%d %d %d", &n, &a, &b);
   if(a == 1) {
      n--;
      if(n % b) puts("No");
      else puts("Yes");
   }
   else {
      ll base = 1;
      while(base <= n) {
         ll rem = n - base;
         if(rem % b == 0) {
            puts("Yes");
            return;
         }
         base *= a;
      }
      puts("No");
   }
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}