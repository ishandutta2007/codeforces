#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e5+5, mod = 1e9+7;

int n, a[sz], csub[sz], cdepth[sz], pdis[19][sz], fdis[19][sz], hdis[19][sz];
vector <pair<int,int>> g[sz];
vector <int> cent[sz], childs[sz];
bool done[sz];

int troid(int u, int tot, int p = 0) {
   for(auto &[v, t] : g[u]) if(v ^ p && !done[v] && (csub[v] << 1) >= tot)
      return troid(v, tot, u);
   return u;
}

void trav(int u, int p = 0) {
   csub[u] = 1;
   for(auto &[v, t] : g[u]) if(v ^ p && !done[v])
      trav(v, u), csub[u] += csub[v];
}

int nowh, nowf, nowc;

void deep(int u, int p, int l, int d, int s) {
   s += a[u]; s %= mod;
   childs[nowc].push_back(u);
   pdis[nowh][u] = d, fdis[nowh][u] = nowf, hdis[nowh][u] = s;
   for(auto &[v, t] : g[u]) if(v ^ p && !done[v]) deep(v, u, t, d + (t ^ l), s);
}

void decomp(int u, int p = 0, int lvl = 0) {
   trav(u);
   int c = troid(u, csub[u]);
   done[c] = 1, cdepth[c] = lvl;
   cent[p].push_back(c);

   childs[c].push_back(c);
   nowh = lvl, nowc = c;
   for(auto &[v, t] : g[c]) if(v ^ p && !done[v]) nowf = t, deep(v, c, t, 0, 0);

   for(auto &[v, t] : g[c]) if(!done[v]) decomp(v, c, lvl + 1);
}

struct fenwick {
   int bit[sz];

   fenwick() {
      memset(bit, 0, sizeof bit);
   }

   void add(int x, int v) {
      x++;
      while(x <= n) {
         bit[x] += v;
         bit[x] >= mod ? bit[x] -= mod : 1;
         bit[x] < 0 ? bit[x] += mod : 1;
         x += x & -x;
      }
   }

   int quer(int x) {
      x++;
      int sum = 0;
      while(x) {
         sum += bit[x];
         sum >= mod ? sum -= mod : 1;
         sum < 0 ? sum += mod : 1;
         x -= x & -x;
      }
      return sum;
   }
};

int main() {
   int k;
   scanf("%d %d", &n, &k);
   for(int i=1; i<=n; i++) scanf("%d", &a[i]);
   for(int i=1; i<n; i++) {
      int u, v, t;
      scanf("%d %d %d", &u, &v, &t);
      g[u].emplace_back(v, t);
      g[v].emplace_back(u, t);
   }
   decomp(1);

   fenwick cnt[2], sum[2];

   ll ans = 0;
   for(int i=1; i<=n; i++) {
      int h = cdepth[i];
      ans += a[i]; ans %= mod;
      for(int j : cent[i]) {
         int f = fdis[h][j];
         for(int v : childs[j]) {
            ll dis = hdis[h][v] + a[i];
            int kcut = pdis[h][v];
            if(kcut > k) continue;
            kcut = k - kcut;

            ans += dis;
            ans += sum[f].quer(kcut);
            ans += sum[f ^ 1].quer(kcut - 1);
            ans += dis * cnt[f].quer(kcut) % mod;
            ans += dis * cnt[f ^ 1].quer(kcut - 1);
            ans %= mod;
         }
         for(int v : childs[j]) {
            int dis = hdis[h][v];
            int kcut = pdis[h][v];
            if(kcut > k) continue;
            sum[f].add(kcut, dis);
            cnt[f].add(kcut, +1);
         }
      }
      for(int j : cent[i]) {
         int f = fdis[h][j];
         for(int v : childs[j]) {
            int dis = hdis[h][v];
            int kcut = pdis[h][v];
            if(kcut > k) continue;
            sum[f].add(kcut, -dis);
            cnt[f].add(kcut, -1);
         }
      }
   }
   cout << ans;
}