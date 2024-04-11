#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+5;

int n, m, s, by[sz], run[sz], k;
vector <int> g[sz], ara;

void go(int v) {
   ara.push_back(v);
   while(by[v] ^ s) {
      v = by[v];
      ara.push_back(v);
   }
   ara.push_back(s);
   reverse(ara.begin(), ara.end());
   printf("%d\n", ara.size());
   for(int x : ara) printf("%d ", x);
   puts("");
   ara.clear();
}

void dfs(int u, int p) {
   if(by[u]) {
      puts("Possible");
      go(u);
      puts("2");
      printf("%d %d\n", s, u);
      exit(0);
   }
   by[u] = p, run[u] = k;
   for(int v : g[u]) if(v ^ s) {
      if(by[v]) {
         if(run[v] ^ k) {
            puts("Possible");
            go(v);
            ara.push_back(v);
            go(u);
            exit(0);
         }
      }
      else dfs(v, u);
   }
}

int main() {
   cin >> n >> m >> s;
   while(m--) {
      int u, v;
      scanf("%d %d", &u, &v);
      g[u].push_back(v);
   }

   for(int b : g[s]) k = b, dfs(b, s);
   puts("Impossible");
}