#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e6+5;

int a[sz], w[sz];

void solve() {
   int n, m, k;
   scanf("%d %d %d", &n, &m, &k);
   for(int i=1; i<=k; i++) scanf("%d", &a[i]), w[a[i]] = i;

   int j = 0, f = n * m - 4;
   priority_queue <int> pq;
   for(int i=k; i; i--) {
      while(j < w[i]) pq.emplace(a[++j]);
      while(!pq.empty() and pq.top() >= i) pq.pop();
      if(pq.size() > f) {
         puts("TIDAK");
         return;
      }
   }
   puts("YA");
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}