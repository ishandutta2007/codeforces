#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e5+5, mod = 1e9+7;

int a[sz];
set <int> st[30];
ll fib[sz], cum[sz];

int main() {
   fib[0] = fib[1] = cum[0] = 1;
   for(int i=2; i<sz; i++) fib[i] = (fib[i-1] + fib[i-2]) % mod;
   for(int i=1; i<sz; i++) cum[i] = (cum[i-1] + fib[i]) % mod;

   int n, p;
   cin >> n >> p;
   for(int i=0; i<n; i++) scanf("%d", &a[i]);
   sort(a, a + n);

   for(int i=0; i<n; i++) {
      bool yes = 1;
      int b = 31 - __builtin_clz(a[i]), x = 0;
      for(int j=b; j>=0 and yes; j--) {
         x |= a[i] & 1 << j;
         int now = x >> j;
         if(st[b-j].count(now)) {
            vector <int> idk;
            for(int k=0; k<j; k++) {
               if(a[i] & 1 << k) idk.push_back(1);
               else idk.push_back(0);
            }
            bool can = 1;
            while(!idk.empty()) {
               if(idk.back() == 1) idk.pop_back();
               else {
                  idk.pop_back();
                  if(idk.empty() or idk.back() == 1) {
                     can = 0;
                     break;
                  }
                  idk.pop_back();
               }
            }
            if(can) yes = 0;
         }
      }
      if(yes) st[b].insert(a[i]);
   }

   ll ans = 0;
   for(int i=0; i<min(30, p); i++) {
      ll c = st[i].size(), rem = p - i - 1;
      ans += c * cum[rem] % mod;
      ans %= mod;
   }
   ans += mod; ans %= mod;
   cout << ans;
}