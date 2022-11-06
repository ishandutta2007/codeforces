#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 205, mod = 1e9+7;

int dep[sz], prnt[sz], jump[sz], csub[sz];
vector <int> g[sz];

void deep(int u) {
   csub[u] = 1;
   for(int v : g[u]) if(v ^ prnt[u]) {
      prnt[v] = u, dep[v] = dep[u] + 1;
      int x = jump[u], y = jump[x];
      jump[v] = dep[u] + dep[y] == dep[x] << 1 ? y : u;
      deep(v);
      csub[u] += csub[v];
   }
}

int getLCA(int u, int v) {
   if(dep[u] < dep[v]) swap(u, v);
   while(dep[u] > dep[v]) u = dep[jump[u]] < dep[v] ? prnt[u] : jump[u];
   while(u ^ v) jump[u] == jump[v] ? (u = prnt[u], v = prnt[v]) : (u = jump[u], v = jump[v]);
   return u;
}

ll bigmod(ll b, ll n) {
   if(n == -1) n = mod - 2;
   ll ans = 1;
   while(n) {
      if(n & 1) ans = ans * b % mod;
      n >>= 1;
      b = b * b % mod;
   }
   return ans;
}

bool vis[sz];
int dis[sz][sz], cnt;

void go(int u) {
   if(!vis[u]) vis[u] = 1, cnt++;
   for(int v : g[u]) if(!vis[v]) go(v);
}

ll fac[sz], finv[sz], inv[sz];

void prec() {
   inv[0] = inv[1] = 1;
   for(int i=2; i<sz; i++)
      inv[i] = mod - mod / i * inv[mod % i] % mod;
   fac[0] = finv[0] = 1;
   for(int i=1; i<sz; i++) {
      fac[i] = fac[i-1] * i % mod;
      finv[i] = finv[i-1] * inv[i] % mod;
   }
}

ll cmb(int x, int y) {
   ll d = fac[x] * fac[y] % mod;
   return finv[x + y] * d % mod;
}

ll dp[sz][sz];
const ll two = 500000004;

ll fnc(int x, int y) {
   if(!x) return 1;
   if(!y) return 0;

   ll &w = dp[x][y];
   if(w >= 0) return w;
   return w = (two * fnc(x - 1, y) + two * fnc(x, y - 1)) % mod;
}

int main() {
//   cout << bigmod(2, -1);
   prec();
   memset(dp, -1, sizeof(dp));

   int n;
   cin >> n;
   for(int i=1; i<n; i++) {
      int u, v;
      scanf("%d %d", &u, &v);
      g[u].push_back(v);
      g[v].push_back(u);
   }
   dep[1] = jump[1] = 1; deep(1);

   for(int i=1; i<=n; i++) {
      queue <int> q; q.push(i);
      for(int j=1; j<=n; j++) dis[i][j] = sz;
      dis[i][i] = 0;
      while(!q.empty()) {
         int u = q.front(), d = dis[i][u] + 1; q.pop();
         for(int v : g[u]) if(dis[i][v] > d) {
            dis[i][v] = d;
            q.push(v);
         }
      }
   }

   ll ans = 0;
   for(int i=1; i<=n; i++) {
      for(int j=i+1; j<=n; j++) {
         int lca = getLCA(i, j);
         memset(vis, 0, sizeof vis);
         vector <int> ara;
         int u = i;
         while(u != lca) vis[u] = 1, ara.push_back(u), u = prnt[u];
         u = j;
         while(u != lca) vis[u] = 1, ara.push_back(u), u = prnt[u];
         vis[lca] = 1;
         ara.push_back(lca);

         for(int u : ara) {
            cnt = 1;
            go(u);
            int di = dis[u][i], dj = dis[u][j];
            ll now = (ll) cnt * fnc(dj, di) % mod;
//            cout << now << endl;
//            now = now * cmb(di, dj) % mod;
            ans += now;
            ans %= mod;
//            printf("-- %d %d %d : %lld\n", u, i, j, now);
         }
//         printf("%d %d %lld\n", i, j, ans);
      }
   }
   ans = ans * bigmod(n, -1) % mod;
   if(ans < 0) ans += mod;
   cout << ans;
}