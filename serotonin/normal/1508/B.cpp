#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll sz = 1e5+5, inf = 1e18;

ll tot[sz];

void solve() {
   int n; ll k;
   scanf("%d %lld", &n, &k);
   if(k > tot[n]) {
      puts("-1");
      return;
   }

   for(int i=1; i<=n; i++) {
      int j = i;
      while(tot[n - j] < k and j < n) {
         k -= tot[n - j];
         j++;
      }
      int r = j;
      while(j >= i) printf("%d ", j--);
      i = r;
   }
   puts("");
}

int main() {
   tot[1] = 1;
   for(int i=2; i<sz; i++) {
      if(tot[i-1] > inf) tot[i] = tot[i-1];
      else tot[i] = tot[i-1] << 1;
   }
   int t;
   cin >> t;
   while(t--) solve();
}