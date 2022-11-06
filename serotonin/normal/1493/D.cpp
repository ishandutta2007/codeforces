#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e5+7, mod = 1e9+7;

int bpf[sz], a[sz], id[sz], val[sz], cnt[sz], ton[sz];
map <int,int> mp[sz];
ll ans[sz];

ll bigmod(ll b, ll n) {
   ll ans = 1;
   if(n == -1) n = mod - 2;
   while(n) {
      if(n & 1) ans = ans * b % mod;
      n >>= 1;
      b = b * b % mod;
   }
   return ans;
}

void sieve() {
   for(int i=2; i<sz; i++) {
      if(bpf[i]) continue;
      for(int j=i; j<sz; j+=i) bpf[j] = i;
   }
}

int main() {
   sieve();
   int n, q;
   cin >> n >> q;
   for(int i=1; i<=n; i++) scanf("%d", &a[i]);
   for(int i=1; i<=q; i++) scanf("%d %d", &id[i], &val[i]);

   for(int i=1; i<=n; i++) {
      int x = a[i];
      while(x > 1) {
         int p = bpf[x], j = 0;
         while(x % p == 0) x /= p, j++;
         mp[i][p] = j;
         cnt[p]++;
      }
   }

   for(int i=1; i<=q; i++) {
      int x = val[i];
      while(x > 1) {
         int p = bpf[x], j = 0;
         while(x % p == 0) x /= p, j++;
         int k = id[i];
         if(mp[k].find(p) == mp[k].end()) cnt[p]++;
         mp[k][p] += j;
      }
   }

   ll res = 1;
   for(int i=2; i<sz; i++) if(cnt[i] == n) {
      int k = INT_MAX;
      for(int j=1; j<=n; j++) k = min(k, mp[j][i]);
      res = res * bigmod(i, k) % mod;
      ton[i] = k;
   }

   ans[q] = res;
   for(int i=q; i>1; i--) {
      int x = val[i];
      while(x > 1) {
         int p = bpf[x], j = 0;
         while(x % p == 0) x /= p, j++;
         int k = id[i];
         mp[k][p] -= j;
         int now = mp[k][p];
         if(now < ton[p]) {
            ll bad = bigmod(p, ton[p] - now);
            ton[p] = now;
            res = res * bigmod(bad, -1) % mod;
         }
      }
      ans[i-1] = res;
   }

   for(int i=1; i<=q; i++) printf("%lld\n", ans[i]);
}