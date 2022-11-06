#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e5+5;

int d[sz], dd[sz];
vector <int> g[sz];

void solve() {
   int n, m;
   scanf("%d %d", &n, &m);
   for(int i=1; i<=n; i++) g[i].clear(), d[i] = 0, dd[i] = n + 20;
   while(m--) {
      int u, v;
      scanf("%d %d", &u, &v);
      g[u].emplace_back(v);
   }

   queue <int> q;
   stack <int> st;
   q.push(1); d[1] = 1;
   while(!q.empty()) {
      int u = q.front(); q.pop(); st.push(u);
      for(int v : g[u]) if(!d[v]) d[v] = d[u] + 1, q.push(v);
   }
   while(!st.empty()) {
      int u = st.top(); st.pop();
      for(int v : g[u]) {
         if(d[v] <= d[u]) dd[u] = min(dd[u], d[v]);
         else dd[u] = min(dd[u], min(d[v], dd[v]));
      }
   }
   for(int i=1; i<=n; i++) printf("%d ", min(d[i], dd[i]) - 1);
   puts("");
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}