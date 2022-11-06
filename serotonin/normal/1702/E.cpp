#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e5+7;

int a[sz], b[sz], cnt[sz], id[sz], xx[sz];

bool dfs(int i, int v, int f) {
   if(id[i]) return id[i] == f;
   id[i] = f;
   int u = a[i] ^ b[i] ^ v;
   int j = xx[u] ^ i;
   return dfs(j, u, f ^ 1);
}

void solve() {
   int n;
   scanf("%d", &n);
   for(int i=1; i<=n; i++) cnt[i] = 0;
   for(int i=1; i<=n; i++) scanf("%d %d", &a[i], &b[i]);
   for(int i=1; i<=n; i++) cnt[a[i]]++, cnt[b[i]]++;
   for(int i=1; i<=n; i++) if(cnt[i] != 2 or a[i] == b[i]) {
      puts("NO");
      return;
   }
   for(int i=1; i<=n; i++) id[i] = xx[i] = 0;
   for(int i=1; i<=n; i++) xx[a[i]] ^= i;
   for(int i=1; i<=n; i++) xx[b[i]] ^= i;

   bool ok = 1;
   for(int i=1; i<=n; i++) if(!id[i]) {
      id[i] = 2;
      int y = b[i];
      int j = xx[y] ^ i;
      ok &= dfs(j, y, 3);
   }
   puts(ok ? "YES" : "NO");
}

int main() {
   int t; cin >> t;
   while(t--) solve();
}