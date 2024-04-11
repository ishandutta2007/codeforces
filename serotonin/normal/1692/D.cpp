#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2000;

bool vis[sz];

void solve() {
   char s[10];
   int p;
   scanf("%s %d", s, &p);

   int bh = (s[0] - '0') * 10 + s[1] - '0';
   int bm = (s[3] - '0') * 10 + s[4] - '0';
   int b = bh * 60 + bm;

   memset(vis, 0, sizeof vis);
   while(!vis[b]) {
      vis[b] = 1;
      b += p;
      if(b >= 1440) b -= 1440;
   }

   int ans = 0;
   for(int i=0; i<1440; i++) {
      if(!vis[i]) continue;
      int h = i / 60, m = i % 60;
      int hx = h / 10, hy = h % 10;
      h = hy * 10 + hx;
      ans += h == m;
   }
   printf("%d\n", ans);
}

int main() {
   int t; cin >> t;
   while(t--) solve();
}