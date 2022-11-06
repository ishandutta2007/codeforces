#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll sz = 2e5+7, inf = 1e15;

typedef pair <ll,ll> pii;
#define x first
#define y second

int n;
pii a[sz];
ll ara[sz][4];
vector <ll> cum[sz << 2][4];
vector <pii> mst[sz << 2];

void init(int u = 1, int b = 0, int e = n - 1) {
   if(b == e) {
      mst[u].emplace_back(a[b].y, b);
      for(int j=0; j<4; j++) cum[u][j] = {ara[b][j]};
      return;
   }
   int md = b + e >> 1, x = u << 1, y = x | 1;
   init(x, b, md), init(y, md + 1, e);
   merge(mst[x].begin(), mst[x].end(), mst[y].begin(), mst[y].end(), back_inserter(mst[u]));

   auto &vec = cum[u];
   int z = mst[u].size();
   for(int j=0; j<2; j++) {
      ll v = -inf;
      vec[j].resize(z);
      for(int i=z-1; i>=0; i--) {
         int k = mst[u][i].y;
         vec[j][i] = v = max(v, ara[k][j]);
      }
   }
   for(int j=2; j<4; j++) {
      ll v = -inf;
      vec[j].resize(z);
      for(int i=0; i<z; i++) {
         int k = mst[u][i].y;
         vec[j][i] = v = max(v, ara[k][j]);
      }
   }
}

ll query(int l, int r, int i, bool f, int u = 1, int b = 0, int e = n - 1) {
   if(r < b or l > e or l > r) return -inf;
   if(l <= b and e <= r) {
      ll ans = -inf;
      int x = upper_bound(mst[u].begin(), mst[u].end(), make_pair(a[i].x + 1, -1LL)) - mst[u].begin();
      if(x < mst[u].size()) ans = max(ans, cum[u][0 ^ f][x] + a[i].x);
      if(x) ans = max(ans, cum[u][2 ^ f][x - 1] - a[i].x);
      return ans;
   }
   int md = b + e >> 1, x = u << 1;
   return max(query(l, r, i, f, x + 1, md + 1, e), query(l, r, i, f, x, b, md));
}

int main() {
   cin >> n;
   ll ans = 0;
   for(int i=0; i<n; i++) scanf("%lld", &a[i].y);
   for(int i=0; i<n; i++) {
      scanf("%lld", &a[i].x);
      ans += abs(a[i].x - a[i].y);
   }
   sort(a, a+n);
   for(int i=0; i<n; i++) {
      for(int j=0; j<4; j++) {
         ll &now = ara[i][j];
         if(j & 1) now += a[i].x;
         else now -= a[i].x;
         if(j & 2) now += a[i].y;
         else now -= a[i].y;
         now += abs(a[i].x - a[i].y);
      }
   }
   init();

   ll res = 0;
   for(int i=1; i<n; i++) {
      ll cut = abs(a[i].x - a[i].y);
      int r = upper_bound(a, a+i, make_pair(a[i].y + 1, 0LL)) - a;
      res = max(res, cut - a[i].y + query(0, r - 1, i, 1));
      res = max(res, cut + a[i].y + query(r, i - 1, i, 0));
   }
   cout << ans - res;
}