#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e5+7;

int a[sz], b[sz], id[sz];
ll can[sz];

void solve() {
   int n, k;
   scanf("%d %d", &n, &k);
   for(int i=1; i<=n; i++) scanf("%d %d", &a[i], &b[i]);

   if(k <= a[1]) {
      puts("Yes");
      return;
   }

   if(k - b[1] > a[1]) {
      puts("No");
      return;
   }

   for(int i=2; i<=n; i++) if(a[i] >= k - b[1]) {
      puts("Yes");
      return;
   }

   if(n == 1) {
      puts("No");
      return;
   }

   for(int i=1; i<=n; i++) id[i] = i;
   sort(id + 2, id + n + 1, [] (int u, int v) {
      if(a[u] != a[v]) return a[u] < a[v];
      return b[u] > b[v];
   });

   can[n + 1] = k - b[1];
   priority_queue <pair<int,int>> pq;
   for(int e=n; e>1; e--) {
      int i = id[e];
      pq.emplace(a[i] + b[i], b[i]);
      can[e] = can[e + 1];
      while(!pq.empty() and pq.top().first >= can[e]) {
         can[e] -= pq.top().second;
         pq.pop();
      }
   }

   int mxsum = -1e9;
   for(int e=2; e<=n; e++) {
      int i = id[e];
      int init_cur = max(mxsum, a[i]);
      mxsum = max(mxsum, a[i] + b[i]);
      if(can[e + 1] <= init_cur) {
         puts("Yes");
         return;
      }
   }
   puts("No");
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}