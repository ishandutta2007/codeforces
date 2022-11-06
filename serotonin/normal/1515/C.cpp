#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e6+7;

int a[sz], c[sz];

void solve() {
   int n, m, x;
   scanf("%d %d %d", &n, &m, &x);
   for(int i=1; i<=n; i++) scanf("%d", &a[i]), c[i] = 0;

   puts("YES");
   priority_queue <pair<int,int>> pq;
   for(int i=1; i<=m; i++) {
      printf("%d ", i);
      c[i] += a[i];
      pq.emplace(-a[i], i);
   }

   for(int i=m+1; i<=n; i++) {
      auto [e, j] = pq.top(); pq.pop();
      printf("%d ", j);
      c[j] += a[i];
      pq.emplace(-c[j], j);
   }
   puts("");
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}