#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+7;

int n, a[sz], b[sz], cumfrom[sz];
vector <int> g[sz];
bool done[sz];

int main() {
   cin >> n;
   for(int i=1; i<=n; i++) scanf("%d", &a[i]), a[i] = i - a[i];
   for(int i=1; i<=n; i++) scanf("%d", &b[i]), b[i] += i;

   for(int i=1; i<=n; i++) g[a[i]].push_back(i);
   for(int i=1; i<=n; i++) cumfrom[b[i]] = max(cumfrom[b[i]], i);

   int u = 0, up = 0, ans = 0;
   vector <int> res;
   while(u < n) {
      res.push_back(u);
      int v = 0;
      while(up <= n) {
         if(g[up].empty()) {
            up++;
            continue;
         }
         int i = g[up].back();
         if(i < u or done[i]) {
            g[up].pop_back();
            continue;
         }
         if(up > u) break;
         done[i] = 1;
         v = max(v, cumfrom[i]);
      }
      ans++;
      if(v <= u) {
         puts("-1");
         return 0;
      }
      u = v;
   }
   printf("%d\n", ans);
   reverse(res.begin(), res.end());
   for(int x : res) printf("%d ", x);
}