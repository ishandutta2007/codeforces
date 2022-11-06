#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 4e6+5;

int n, a[sz];

int ask1(int i, int j, int x) {
   printf("? 1 %d %d %d\n", i, j, x); fflush(stdout);
   scanf("%d", &x);
   return x;
}

int ask2(int i, int j, int x) {
   printf("? 2 %d %d %d\n", i, j, x); fflush(stdout);
   scanf("%d", &x);
   return x;
}

void solve() {
   int n;
   scanf("%d", &n);
   int x = ask1(1, 2, n - 1);
   if(x == n - 1) x = ask1(2, 1, n - 1);
   int y = ask2(1, 2, 1);
   if(y == 2) y = ask2(2, 1, 1);
   if(x > y) swap(x, y);

   if(ask1(1, 2, x) != x) a[1] = x, a[2] = y;
   else a[1] = y, a[2] = x;

   if(a[1] > n / 2) {
      vector <int> ara;
      for(int i=3; i<=n; i++) {
         int z = ask2(i, 1, 1);
         if(z < a[1]) a[i] = z;
         else ara.push_back(i);
      }
      for(int i : ara) a[i] = ask1(1, i, n - 1);
   }
   else {
      vector <int> ara;
      for(int i=3; i<=n; i++) {
         int z = ask1(1, i, n - 1);
         if(z > a[1]) a[i] = z;
         else ara.push_back(i);
      }
      for(int i : ara) a[i] = ask2(i, 1, 1);
   }
   printf("!");
   for(int i=1; i<=n; i++) printf(" %d", a[i]);
   puts(""); fflush(stdout);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}