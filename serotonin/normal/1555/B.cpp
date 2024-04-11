#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e5+7;

void solve() {
   int w, h;
   cin >> w >> h;
   int x1, y1, x2, y2;
   cin >> x1 >> y1 >> x2 >> y2;
   int tw, th;
   cin >> tw >> th;

   int dw = x2 - x1, dh = y2 - y1;
   if(dw + tw > w and dh + th > h) {
      cout << "-1" << '\n';
      return;
   }

   int ans = max(w, h);
   if(dw + tw <= w) ans = min({ans, tw - x1, x2 - (w - tw)});
   if(dh + th <= h) ans = min({ans, th - y1, y2 - (h - th)});
   ans = max(ans, 0);
   cout << ans << '\n';
}

int main() {
   ios_base::sync_with_stdio(0); cin.tie(0);
   int t;
   cin >> t;
   while(t--) solve();
}