#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 4e5+7;

char s[111];
vector <int> g[sz];
set <int> st;
bool done[sz];

void dfs(int u) {
   done[u] = 1;
   st.insert(u);
   for(int v : g[u]) if(!done[v]) dfs(v);
}

void solve() {
   int n, m;
   scanf("%d %d", &n, &m);
   int z = n << 1 | 1;
   for(int i=2; i<=z; i++) g[i].clear(), done[i] = 0;
   while(m--) {
      int u, v;
      scanf("%d %d %s", &u, &v, s);
      u <<= 1, v <<= 1;
      if(s[0] == 'i') v ^= 1;
      g[u].push_back(v);
      g[v].push_back(u);
      u ^= 1, v ^= 1;
      g[u].push_back(v);
      g[v].push_back(u);
   }
   int ans = 0;
   for(int i=2; i<=z; i++) {
      if(done[i]) continue;
      st.clear();
      dfs(i);
      int c = 0;
      for(int x : st) {
         if(~x & 1 and st.count(x | 1)) {
            puts("-1");
            return;
         }
         c += x & 1;
      }
      int k = st.size();
      ans += max(k - c, c);
   }
   printf("%d\n", ans / 2);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}