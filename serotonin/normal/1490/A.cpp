#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e5+5;

int a[sz];

void solve() {
   int n;
   scanf("%d", &n);
   for(int i=0; i<n; i++) scanf("%d", &a[i]);
   int ans = 0;
   for(int i=1; i<n; i++) {
      int x = a[i-1], y = a[i];
      if(x > y) swap(x, y);
      while(x * 2 < y) ans++, x <<= 1;
   }
   printf("%d\n", ans);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}