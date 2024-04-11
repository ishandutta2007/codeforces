#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 505, mod = 998244353;

int n, j, a[sz], f[sz], dp[sz][sz];

int fnc(int i, int c) {
   if(i > n) return 1;
   int &w = dp[i][c];
   if(w >= 0) return w;
   w = fnc(i + 1, c);
   if(i == j) return w;
   if(i < j) {
      if(f[i]) w += fnc(i + 1, c + (a[i] < a[j]));
      else w += fnc(i + 1, max(c - 1, 0));
   }
   else {
      if(f[i]) w += fnc(i + 1, c + (a[i] <= a[j]));
      else if(c) w += fnc(i + 1, c - 1);
   }
   if(w >= mod) w -= mod;
   return w;
}

int main() {
   cin >> n;
   for(int i=1; i<=n; i++) {
      char s[5];
      scanf("%s", s);
      f[i] = s[0] == '+';
      if(f[i]) scanf("%d", &a[i]);
   }

   ll ans = 0;
   for(int i=1; i<=n; i++) {
      if(!f[i]) continue;
      memset(dp, -1, sizeof(dp));
      j = i;
      ans += (ll) fnc(1, 0) * a[i] % mod;
      ans %= mod;
   }
   if(ans < 0) ans += mod;
   cout << ans;
}