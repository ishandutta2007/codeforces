#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 4e5+5, rt = 333;

int n, a[sz], bpf[sz], last[sz], block[sz], cnt[sz], bout[sz];

int main() {
   for(int i=2; i<sz; i++) {
      if(bpf[i]) continue;
      for(int j=i; j<sz; j+=i) bpf[j] = i;
   }

   int q;
   scanf("%d %d", &n, &q);
   for(int i=1; i<=n; i++) scanf("%d", &a[i]);

   for(int i=0; i<sz; i++) last[i] = n+1;
   for(int i=n; i; i--) {
      int x = a[i], &b = block[i] = n+1;
      if(i < n) b = block[i+1];

      while(x > 1) {
         int y = bpf[x];
         while(x % y == 0) x /= y;
         b = min(b, last[y]);
         last[y] = i;
      }

      int j = i / rt, k = b / rt;
      if(k == j and b <= n) {
         cnt[i] = 1 + cnt[b];
         bout[i] = bout[b];
      }
      else {
         cnt[i] = 1;
         bout[i] = b;
      }
   }
   while(q--) {
      int l, r, ans = 0;
      scanf("%d %d", &l, &r);
      while(bout[l] <= r) {
         ans += cnt[l];
         l = bout[l];
      }
      while(l <= r) {
         ans++;
         l = block[l];
      }
      printf("%d\n", ans);
   }
}