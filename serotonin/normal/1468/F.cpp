#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1e5+7;

typedef pair <int,int> pii;
#define x first
#define y second

int main() {
   int t;
   cin >> t;
   while(t--) {
      int n;
      scanf("%d", &n);
      map <pii,int> mp;
      for(int i=0; i<n; i++) {
         int x, y, u, v;
         scanf("%d %d %d %d", &x, &y, &u, &v);
         int dx = u - x, dy = v - y;
         int g = __gcd(abs(dx), abs(dy));
         dx /= g, dy /= g;
         mp[make_pair(dx, dy)]++;
      }

      ll ans = 0;
      for(auto it : mp) {
         pii p = it.x;
         p.x = -p.x;
         p.y = -p.y;
         if(mp.find(p) == mp.end()) continue;
         ans += 1LL * it.y * mp[p];
      }
      printf("%lld\n", ans / 2);
   }
}