#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1e5+5, rt = 300;

int a[sz], ql[sz], qr[sz], ans[sz], ara[sz];

vector <int> g[sz];

void add(priority_queue <int> &pq, int x) {
   pq.push(x);
   if(pq.size() > 33) pq.pop();
}

int fnc(priority_queue <int> &pq) {
   int n = 0;
   while(!pq.empty()) ara[n++] = pq.top(), pq.pop();
   int res = ara[0] | ara[1];
   for(int i=0; i<n; i++) {
      for(int j=i+1; j<n; j++) {
         res = min(res, ara[i] | ara[j]);
      }
   }
   return res;
}

void solve() {
   int n;
   scanf("%d", &n);
   for(int i=0; i<n; i++) scanf("%d", &a[i]);

   int q, rhs = 1;
   scanf("%d", &q);
   for(int i=0; i<q; i++) {
      int x, y;
      scanf("%d %d", &x, &y);
      x--, y--;
      ql[i] = x, qr[i] = y;
      g[x / rt].push_back(i);
      rhs = max(rhs, x / rt + 1);
   }
   
   for(int i=1; i<=rhs; i++) {
      int j = i * rt;
      priority_queue <int> pq;
      sort(g[i-1].begin(), g[i-1].end(), [](int x, int y) {
         return qr[x] < qr[y];
      });
      for(int id : g[i-1]) {
         int l = ql[id], r = qr[id];
         if(r < i * rt) {
            priority_queue <int> now;
            for(int k=l; k<=r; k++) add(now, a[k]);
            ans[id] = fnc(now);
            continue;
         }
         while(j <= r) add(pq, a[j++]);
         auto now = pq;
         int li = i * rt;
         while(li > l) add(now, a[--li]);
         ans[id] = fnc(now);
      }
      g[i-1].clear();
   }

   for(int i=0; i<q; i++) printf("%d\n", ans[i]);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}