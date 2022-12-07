#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 4e5+5, mod = 998244353;

int a[sz], ara[sz];

void solve() {
   int n, m;
   scanf("%d %d", &n, &m);
   for(int i=0; i<n; i++) scanf("%d", &a[i]);

   for(int i=1; i<n; i++) if(a[i-1] % a[i]) {
      puts("0");
      return;
   }

   vector <int> primes;
   {
      int x = a[0];
      for(int i=2; i*i<=x; i++) {
         if(x % i == 0) {
            int v = 1;
            while(x % i == 0) x /= i, v *= i;
            primes.push_back(i);
         }
      }
      if(x > 1) primes.push_back(x);
   }

   ll ans = 1;
   for(int i=1; i<n; i++) {
      int x = a[i-1] / a[i], k = 0;
      for(int &p : primes) {
         int c = 0;
         while(x % p == 0) x /= p, c++;
         if(c) ara[k++] = p;
      }
      int now = 0;
      for(int j=0; j<1<<k; j++) {
         int v = a[i], c = 0;
         for(int e=0; e<k; e++) if(j & 1 << e) {
            v *= ara[e];
            c++;
         }
         if(c & 1) now -= m / v;
         else now += m / v;
      }
      ans = ans * now % mod;
   }
   printf("%lld\n", ans);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}