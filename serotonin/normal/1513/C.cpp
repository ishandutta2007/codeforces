#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+7, mod = 1e9+7;

ll sum[10][sz];

void solve() {
   int n, m;
   scanf("%d %d", &n, &m);
   ll ans = 0;
   while(n) {
      ans += sum[n % 10][m];
      n /= 10;
   }
   ans %= mod;
   if(ans < 0) ans += mod;
   printf("%lld\n", ans);
}

void prec() {
   for(int d=0; d<10; d++) {
      ll cnt[10] = {};
      cnt[d]++;
      sum[d][0] = 1;
      for(int i=1; i<sz; i++) {
         ll nine = cnt[9];
         for(int j=9; j; j--) cnt[j] = cnt[j-1];
         cnt[0] = nine;
         cnt[1] += nine; cnt[1] %= mod;
         ll &w = sum[d][i];
         for(int j=0; j<10; j++) w += cnt[j];
         w %= mod;
      }
   }
}

int main() {
   prec();
   int t;
   cin >> t;
   while(t--) solve();
}