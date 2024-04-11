#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e5+5, mod = 998244353;

int k, a[sz], val[sz], cnt[sz];

int tree[sz << 2], ex[sz << 2], cum[sz << 2];
bool zer[sz << 2];

void init(int u = 1, int b = 1, int e = k) {
   if(b == e) {
      cum[u] = cnt[e];
      return;
   }
   int m = b + e >> 1, x = u << 1, y = x + 1;
   init(y, m+1, e); init(x, b, m);
   cum[u] = cum[x] + cum[y];
   cum[u] %= mod;
}

void push(int u, int b, int e) {
   if(zer[u]) tree[u] = 0;
   tree[u] += (ll) cum[u] * ex[u] % mod;
   tree[u] %= mod;
   
   if(b ^ e) {
      int x = u << 1, y = x + 1;
      if(zer[u]) {
         zer[x] = zer[y] = 1;
         ex[x] = ex[y] = 0;
      }
      ex[x] += ex[u], ex[y] += ex[u];
      ex[x] %= mod, ex[y] %= mod;
   }
   ex[u] = zer[u] = 0;
}

void update(int l, int r, int w, int u = 1, int b = 1, int e = k) {
   if(ex[u] or zer[u]) push(u, b, e);
   if(e < l or r < b or l > r) return;
   if(l <= b and e <= r) {
      ex[u] = w;
      return push(u, b, e);
   }
   int m = b + e >> 1, x = u << 1, y = x + 1;
   update(l, r, w, x, b, m);
   update(l, r, w, y, m+1, e);
   tree[u] = (tree[x] + tree[y]) % mod;
}

void modify(int l, int r, int u = 1, int b = 1, int e = k) {
   if(ex[u] or zer[u]) push(u, b, e);
   if(e < l or r < b or l > r) return;
   if(l <= b and e <= r) {
      zer[u] = 1;
      return push(u, b, e);
   }
   int m = b + e >> 1, x = u << 1, y = x + 1;
   modify(l, r, x, b, m);
   modify(l, r, y, m+1, e);
   tree[u] = (tree[x] + tree[y]) % mod;
}

int query() {
   if(ex[1] or zer[1]) push(1, 1, k);
   return tree[1];
}

int main() {
   int n;
   cin >> n;
   set <int> st;
   for(int i=1; i<=n; i++) scanf("%d", &a[i]), st.insert(a[i]);
   for(int x : st) {
      int c = x - val[k];
      val[++k] = x;
      cnt[k] = c;
   }
   init();

   int b = lower_bound(val, val + k + 1, a[1]) - val;
   update(1, b, 1);

   for(int i=2; i<=n; i++) {
      int tot = -query();
      if(tot < 0) tot += mod;

      int j = lower_bound(val, val + k + 1, a[i]) - val;
      modify(j + 1, k, 1);
      update(1, j, tot);
   }
   int ans = query();
   if(~n & 1) ans = -ans;
   if(ans < 0) ans += mod;
   cout << ans;
}