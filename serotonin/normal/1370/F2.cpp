#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1001;

/// screw these rounds

typedef pair <int, int> pii;
#define x first
#define y second

struct action {
   vector <int> ara;

   void add(int x) {
      ara.push_back(x);
   }

   pii query() {
      cout << "? " << ara.size() << endl;
      for(int x : ara) cout << x << " ";
      cout << endl;
      ara.clear();

      pii p;
      cin >> p.x >> p.y;
      if(p.x < 0) exit(0);
      return p;
   }
};

int who[sz], par[sz];
vector <int> g[sz], dep[sz];

int dfs(int u, int p = 0, int lvl = 0)
{
   int res = lvl;
   dep[lvl].push_back(u), par[u] = p;
   for(int v : g[u]) if(v ^ p) res = max(res, dfs(v, u, lvl + 1));
   return res;
}

int main()
{
   int t;
   cin >> t;
   while(t--) {
      int n;
      cin >> n;
      for(int i=1; i<n; i++) {
         int u, v;
         scanf("%d %d", &u, &v);
         g[u].push_back(v);
         g[v].push_back(u);
      }

      action act;
      for(int i=1; i<=n; i++) act.add(i);

      pii p = act.query();
      int d = p.y, rt = p.x;

      int lo = d + 1 >> 1, hi = min(dfs(rt), d);
      while(lo < hi) {
         int md = lo + hi + 1 >> 1;
         act.ara = dep[md];
         p = act.query();
         who[md] = p.x;
         if(p.y ^ d) hi = md - 1;
         else lo = md;
      }

      if(!who[lo]) {
         act.ara = dep[lo];
         who[lo] = act.query().x;
      }

      for(int i=0; i<sz; i++) dep[i].clear();
      dfs(who[lo]);

      int ans = dep[d][0];
      if(dep[d].size() > 1) {
         act.ara = dep[d];
         ans = act.query().x;
      }

      cout << "! " << who[lo] << " " << ans << endl;

      string s;
      cin >> s;
      if(s[0] == 'I') exit(0);
      for(int i=0; i<sz; i++) g[i].clear(), dep[i].clear(), who[i] = 0;
   }
}