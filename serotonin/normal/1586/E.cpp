#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+7;

vector <int> g[sz];

set <int> st[sz];

bool done[sz];

int stk[sz], k;

vector <int> ans[sz];

int qid;

bool dfs(int u, int t) {
   done[u] = 1;
   stk[++k] = u;
   if(u == t) {
      while(k) ans[qid].push_back(stk[k--]);
      return 1;
   }
   for(int v : st[u]) if(!done[v]) {
      if(dfs(v, t)) return 1;
   }
   k--;
   return 0;
}

struct dsu {
   int id[sz], r[sz];

   void init(int n) {
      for(int i=1; i<=n; i++) id[i] = i, r[i] = 1;
   }

   int root(int x) {
      return id[x] = id[x] ^ x ? root(id[x]) : x;
   }

   bool unite(int x, int y) {
      x = root(x), y = root(y);
      if(x == y) return 0;
      if(r[x] < r[y]) swap(x, y);
      r[x] += r[y]; id[y] = x;
      return 1;
   }
} mst;

bool go(int u, int t) {
   done[u] = 1;
   stk[++k] = u;
   if(u == t) {
      printf("%d\n", k);
      while(k) printf("%d ", stk[k--]); puts("");
      return 1;
   }
   for(int v : g[u]) if(!done[v]) {
      if(go(v, t)) return 1;
   }
   k--;
   return 0;
}

int main() {
   int n, m;
   cin >> n >> m;
   mst.init(n);
   while(m--) {
      int u, v;
      scanf("%d %d", &u, &v);
      if(mst.unite(u, v)) {
         g[u].push_back(v);
         g[v].push_back(u);
      }
   }

   int q;
   cin >> q;
   for(; qid<q; qid++) {
      int s, t;
      scanf("%d %d", &s, &t);
      k = 0;
      for(int i=1; i<=n; i++) done[i] = 0;
      if(dfs(s, t)) {
         for(int i=1; i<ans[qid].size(); i++) {
            int u = ans[qid][i], v = ans[qid][i-1];
            st[u].erase(v);
            st[v].erase(u);
         }
      }
      else {
         st[s].insert(t);
         st[t].insert(s);
         ans[qid].push_back(t);
         ans[qid].push_back(s);
      }
   }

   bool nope = 0;
   for(int i=1; i<=n; i++) if(!st[i].empty()) nope = 1;

   if(!nope) {
      puts("YES");
      for(int i=0; i<q; i++) {
         int t = ans[i][0], s = ans[i].back();
         k = 0;
         for(int i=1; i<=n; i++) done[i] = 0;
         go(t, s);
      }
      return 0;
   }

   puts("NO");
   int odd = 0;
   for(int i=1; i<=n; i++) odd += (int)st[i].size() & 1;
   cout << odd / 2;
}