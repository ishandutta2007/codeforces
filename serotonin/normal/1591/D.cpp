#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 5e5+5;

int a[sz], b[sz];
bool vis[sz];
pair <int,int> p[sz];

void solve() {
   int n;
   scanf("%d", &n);
   for(int i=1; i<=n; i++) scanf("%d", &a[i]), b[i] = a[i], vis[i] = 0;
   sort(b+1, b+n+1);

   for(int i=2; i<=n; i++) if(b[i] == b[i-1]) {
      puts("YES");
      return;
   }
   
   int k = 0;
   for(int i=1; i<=n; i++) if(a[i] ^ b[i]) a[++k] = a[i];
   n = k;

   for(int i=1; i<=n; i++) p[i] = {a[i], i};
   sort(p+1, p+n+1);
   for(int i=1; i<=n; i++) a[p[i].second] = i;

   int cnt = 0;
   for(int i=1; i<=n; i++) {
      if(vis[i]) continue;
      int u = i, c = 1;
      while(!vis[u]) {
         vis[u] = 1;
         u = a[u];
         c++;
      }
      cnt += c & 1;
   }
   puts(cnt & 1 ? "NO" : "YES");
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}