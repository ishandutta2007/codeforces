#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 5e5+5, mod = 1e9+7;

int n, m;
int id[sz], r[sz];
vector <int> ans;
bitset <sz> done;

int root(int x) {
   while(id[x] ^ x) x = id[x];
   return x;
}

int main() {
   scanf("%d %d", &n, &m);
   for(int i=1; i<=m; i++) id[i] = i, r[i] = 1;
   for(int i=1; i<=n; i++) {
      int k, x, y;
      scanf("%d", &k);
      if(k == 1) {
         scanf("%d", &x);
         x = root(x);
         if(!done[x]) ans.push_back(i), done[x] = 1;
      }
      else {
         scanf("%d %d", &x, &y);
         x = root(x);
         y = root(y);
         if(x ^ y and (!done[x] or !done[y])) {
            ans.push_back(i);
            if(r[x] < r[y]) {
               if(done[x]) done[y] = 1;
               id[x] = y, r[y] += r[x];
            }
            else {
               if(done[y]) done[x] = 1;
               id[y] = x, r[x] += r[y];
            }
         }
      }
   }

   ll v = 1;
   int tot = ans.size();
   for(int i=0; i<tot; i++) v = (v << 1) % mod;

   printf("%lld %d\n", v, tot);
   sort(ans.begin(), ans.end());
   for(int x : ans) printf("%d ", x);
}