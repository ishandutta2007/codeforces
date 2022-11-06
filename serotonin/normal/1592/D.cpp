#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 4e5+5;

vector <int> g[sz], a;
vector <pair<int,int>> e;

void dfs(int u, int p) {
   for(int v : g[u]) if(v ^ p) {
      e.emplace_back(u, v);
   }
   for(int v : g[u]) if(v ^ p) dfs(v, u);
}

int ask() {
   sort(a.begin(), a.end());
   a.erase(unique(a.begin(), a.end()), a.end());
   printf("? %d", a.size());
   for(int x : a) printf(" %d", x); cout << endl;
   int x;
   scanf("%d", &x);
   return x;
}

int main() {
   int n;
   cin >> n;
   for(int i=1; i<n; i++) {
      int u, v;
      scanf("%d %d", &u, &v);
      g[u].push_back(v);
      g[v].push_back(u);
   }
   dfs(1, 0);

   for(int i=1; i<=n; i++) a.push_back(i);
   int mx = ask();

   int lo = 0, hi = n - 1;
   while(lo < hi) {
      int md = lo + hi >> 1;
      a.clear();
      for(int i=lo; i<=md; i++) {
         a.push_back(e[i].first);
         a.push_back(e[i].second);
      }
      if(ask() == mx) hi = md;
      else lo = md + 1;
   }
   printf("! %d %d\n", e[lo].first, e[lo].second);
}