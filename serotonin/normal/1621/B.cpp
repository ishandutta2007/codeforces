#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e6+7;

typedef pair <int,int> pii;
#define x first
#define y second

void solve() {
   int n;
   scanf("%d", &n);
   pii l, r; int lc, rc;
   scanf("%d %d %d", &l.x, &l.y, &lc);
   r = l, rc = lc;
   printf("%d\n", rc);

   pii one; int oc;
   one = l; oc = lc;

   for(int i=2; i<=n; i++) {
      int x, y, c;
      scanf("%d %d %d", &x, &y, &c);

      if(x < l.x) {
         l = {x, y};
         lc = c;
      }
      else if(x == l.x) {
         if(c < lc) {
            l = {x, y};
            lc = c;
         }
      }

      if(y > r.y) {
         r = {x, y};
         rc = c;
      }
      else if(y == r.y) {
         if(c < rc) {
            r = {x, y};
            rc = c;
         }
      }

      
      int cx = l.x, cy = r.y;

      if(cx < one.x or one.y < cy) {
         oc = INT_MAX;
      }
      
      int ans = lc + rc;

      if(x <= cx and cy <= y) {
         oc = min(oc, c);
         one = {x, y};
      }

      printf("%d\n", min(ans, oc));
   }
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}