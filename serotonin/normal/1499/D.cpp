#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e7+7;

int c, d, x, ans, spf[sz], cnt[sz];

inline void fnc(int dv) {
   int now = dv + d;
   if(now % c) return;
   now /= c;
   ans += 1 << cnt[now];
}

void solve() {
   scanf("%d %d %d", &c, &d, &x);
   ans = 0;
   for(int i=1; i*i<=x; i++) {
      if(x % i) continue;
      fnc(i);
      if(i * i != x) fnc(x / i);
   }
   printf("%d\n", ans);
}

void sieve() {
   for(int i=2; i<sz; i++) {
      if(~i & 1) spf[i] = 2;
      if(!spf[i]) {
         spf[i] = i;
         if(i < sz/i) for(int j=i*i; j<sz; j+=i<<1) if(!spf[j]) spf[j] = i;
      }
      int j = i / spf[i];
      cnt[i] = cnt[j] + (spf[i] != spf[j]);
   }
}

int main() {
   sieve();
   int t;
   cin >> t;
   while(t--) solve();
}