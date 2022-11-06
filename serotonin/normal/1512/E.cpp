#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1e6+7;

int ans[sz];
bool vis[sz];

void solve() {
   int n, l, r, s;
   scanf("%d %d %d %d", &n, &l, &r, &s);
   int d = r - l + 1;
   int mn = d * (d + 1) / 2;
   if(d > s) {
      puts("-1");
      return;
   }

   for(int i=1; i<=n; i++) vis[i] = 0;
   for(int i=0, j=l, x=n; i<d; i++, j++, x--) {
      int r = d - i - 1;
      mn = r * (r + 1) / 2;
      x = min(s - mn, x);
      ans[j] = x;
      s -= x;
      vis[x] = 1;
   }

   if(s) {
      puts("-1");
      return;
   }

   for(int i=1, j=1; i<=n; i++) {
      if(l <= i and i <= r) continue;
      while(vis[j]) j++;
      vis[j] = 1;
      ans[i] = j;
   }

   for(int i=1; i<=n; i++) printf("%d ", ans[i]);
   puts("");
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}