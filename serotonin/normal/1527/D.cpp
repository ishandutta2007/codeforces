#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e5+5;

int dep[sz], prnt[sz], jump[sz], csub[sz];
vector <int> g[sz];
ll dp[sz];

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

int getTWO(int u, int v) {
   int d = dep[v] + 1;
   while(dep[u] > d) u = dep[jump[u]] < d ? prnt[u] : jump[u];
   return u;
}

ll fnc(int u, int v, int c) {
   if(!c) return 0;
   if(c == v) return (ll) csub[u] * (csub[1] - csub[getTWO(u, v)]);
   return (ll) csub[u] * csub[v];
}

void solve() {
   int n;
   cin >> n;
   for(int i=1; i<=n; i++) g[i].clear();
   for(int i=1; i<n; i++) {
      int u, v;
      scanf("%d %d", &u, &v);
      u++, v++;
      g[u].push_back(v);
      g[v].push_back(u);
   }
   dep[1] = jump[1] = 1; deep(1);

   int u = 1, v = 2, c = getLCA(u, v);
   if(dep[u] < dep[v]) swap(u, v);
   dp[2] = fnc(u, v, c);

   for(int i=3; i<=n; i++) {
      if(c == v) {
         int x = getLCA(i, u);
         if(x == u) u = i;
         else if(getLCA(i, v) == i) v = c = i;
         else if(getLCA(i, c) == c) {
            if(x == i) {}
            else if(x == c) v = i;
            else c = 0;
         }
         else c = 0;
      }
      else if(c) {
         if(getLCA(i, u) == u) u = i;
         else if(getLCA(i, v) == v) v = i;
         else if(getLCA(i, c) == c and (getLCA(i, u) == i or getLCA(i, v) == i)) {}
         else c = 0;
      }
      dp[i] = fnc(u, v, c);
   }

   dp[0] = 0;
   for(int v : g[1]) {
      ll x = csub[v];
      dp[0] += x * (x - 1) / 2;
   }
   dp[1] = n * (n - 1LL) / 2 - dp[0];

   printf("%lld", dp[0]);
   for(int i=1; i<n; i++) printf(" %lld", dp[i] - dp[i+1]);
   printf(" %lld\n", dp[n]);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}