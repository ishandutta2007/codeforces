#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+5;

int n, a[sz];

inline bool fnc(int i) {
   if(i <= 1 or i >= n) return 0;
   if(a[i] > a[i-1] and a[i] > a[i+1]) return 1;
   if(a[i] < a[i-1] and a[i] < a[i+1]) return 1;
   return 0;
}

void solve() {
   scanf("%d", &n);
   for(int i=1; i<=n; i++) scanf("%d", &a[i]);

   int ans = 0;
   for(int i=1; i<=n; i++) ans += fnc(i);

   int mn = 0;
   for(int i=1; i<=n; i++) {
      int x = a[i], now = fnc(i-1) + fnc(i) + fnc(i+1), og = now;
      a[i] = a[i-1] - 1;
      now = min(now, fnc(i-1) + fnc(i) + fnc(i+1));
      a[i] = a[i-1] + 1;
      now = min(now, fnc(i-1) + fnc(i) + fnc(i+1));
      a[i] = a[i-1];
      now = min(now, fnc(i-1) + fnc(i) + fnc(i+1));
      a[i] = a[i+1] - 1;
      now = min(now, fnc(i-1) + fnc(i) + fnc(i+1));
      a[i] = a[i+1] + 1;
      now = min(now, fnc(i-1) + fnc(i) + fnc(i+1));
      a[i] = a[i+1];
      now = min(now, fnc(i-1) + fnc(i) + fnc(i+1));
      a[i] = x;
      mn = min(mn, now - og);
   }

   printf("%d\n", ans + mn);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}