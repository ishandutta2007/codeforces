#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2005;

int n, a[sz], g[30];
bool vis[30], ke[30];

void go(int i) {
   vis[i] = 1;
   for(int j=0; j<30; j++) if(!vis[j] and g[i] & 1 << j) go(j);
}

int fnc() {
   memset(g, 0, sizeof g);
   for(int i=1; i<=n; i++) {
      for(int j=0; j<30; j++) if(a[i] & 1 << j) g[j] |= a[i];
   }
   int res = 0;
   memset(ke, 0, sizeof ke);
   memset(vis, 0, sizeof vis);
   for(int i=0; i<30; i++) if(!g[i]) vis[i] = 1;
   for(int i=0; i<30; i++) if(!vis[i]) res++, go(i), ke[i] = 1;
   if(res <= 1) return 0;
   if(g[0]) res--;
   return res;
}

void solve() {
   int tot = 0;
   scanf("%d", &n);
   for(int i=1; i<=n; i++) scanf("%d", &a[i]);
   for(int i=1; i<=n; i++) if(!a[i]) tot++, a[i] = 1;

   tuple <int,int,int> ans = {fnc(), 0, 0};
   for(int i=1; i<=n; i++) {
      for(int j=0, k=0; j<6; j++) {
         k |= 1 << j;
         int c = (a[i] & k) + 1;
         if(c >= a[i]) continue;
         a[i] -= c;
         tuple <int,int,int> now = {c + fnc(), i, c};
         ans = min(ans, now);
         a[i] += c;
      }
   }
   auto [sum, k, c] = ans;
   printf("%d\n", sum + tot);
   
   a[k] -= c;
   fnc();
   for(int i=1; i<=n; i++) {
      for(int j=1; j<30 and sum; j++) if(a[i] & 1 << j and ke[j]) {
         a[i]++;
         ke[j] = 0;
         break;
      }
      printf("%d ", a[i]);
   }
   puts("");
}

int main() {
   int t; 
   cin >> t;
   while(t--) solve();
}