#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 5e5+5;

char s[sz];
ll al[sz], ar[sz], cum[sz];

void solve() {
   int n, c, q;
   scanf("%d %d %d", &n, &c, &q);
   scanf("%s", s + 1);
   for(int i=1; i<=c; i++) scanf("%lld %lld", &al[i], &ar[i]);
   cum[0] = n;
   for(int i=1; i<=c; i++) cum[i] = cum[i-1] + ar[i] - al[i] + 1;
   while(q--) {
      ll k;
      scanf("%lld", &k);
      for(int i=c; i; i--) if(cum[i] >= k and k > cum[i-1]) {
         k = k - cum[i-1] + al[i] - 1;
      }
      printf("%c\n", s[k]);
   }
}

int main() {
   int t; cin >> t;
   while(t--) solve();
}