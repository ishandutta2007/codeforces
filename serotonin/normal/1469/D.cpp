#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e5;

int cnt(int x, int y) {
   if(x < y) swap(x, y);
   if(x <= 2 && y <= 1) return 0;
   if(y == 1) return sz;
   return 1 + cnt(y, 1 + (x - 1) / y);
}

void solve() {
   int n;
   scanf("%d", &n);
   if(n == 3) {
      puts("2");
      puts("3 2");
      puts("3 2");
      return;
   }
   for(int i=min(n-1, (int)sqrt(n)+20); i>2; i--) {
      int now = cnt(n, i);
      if(now <= 8) {
         printf("%d\n", now + n-3);
         for(int j=2; j<n; j++) {
            if(i == j) continue;
            printf("%d %d\n", j, n);
         }
         int x = n, y = i;
         while(1) {
            if((x <= 2 and y <= 1) or (y <= 2 and x <= 1)) break;
            if(x > y) {
               printf("%d %d\n", n, i);
               x = 1 + (x - 1) / y;
            }
            else {
               printf("%d %d\n", i, n);
               y = 1 + (y - 1) / x;
            }
         }
         return;
      }
   }
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}