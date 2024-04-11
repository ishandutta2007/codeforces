#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e5+5;

int n, m, k, a[sz];
char s[sz][7], p[sz][7];
map <string,int> mp;

bool no;
int color[sz];
bitset <sz> vis;
vector <int> g[sz], ts;

void dfs(int u) {
   vis[u] = 1;
   for(int v : g[u]) if(!vis[v]) dfs(v);
   ts.push_back(u);
}

void t_sort(int n) {
   ts.clear();
   for(int i=1; i<=n; i++) if(!vis[i]) dfs(i);
   reverse(ts.begin(), ts.end());
}

void go(int u, int p) {
   color[u] = 1;
   for(int v : g[u]) {
      if(no) return;
      if(color[v] == 1) {
         no = 1;
         return;
      }
      if(!color[v]) go(v, u);
   }
   color[u] = 2;
}

bool match(char str[], char pat[]) {
   for(int i=0; i<k; i++) if(pat[i] != '_' and str[i] != pat[i]) return 0;
   return 1;
}

int main() {
   cin >> n >> m >> k;
   for(int i=1; i<=n; i++) {
      scanf("%s", p[i]);
      string d = p[i];
      mp[d] = i;
   }
   for(int i=1; i<=m; i++) scanf("%s %d", s[i], &a[i]);

   for(int i=1; i<=m; i++) {
      if(!match(s[i], p[a[i]])) {
         puts("NO");
         return 0;
      }

      for(int j=0; j<(1<<k); j++) {
         string now = s[i];
         for(int r=0; r<k; r++) if(j & 1 << r) now[r] = '_';
         if(mp.find(now) != mp.end()) {
            int id = mp[now];
            if(id == a[i]) continue;
            g[a[i]].push_back(id);
         }
      }
   }

   for(int i=1; i<=n; i++) if(!color[i]) go(i, -1);

   if(no) {
      puts("NO");
      return 0;
   }

   t_sort(n);
   puts("YES");
   for(int x : ts) printf("%d ", x);
}