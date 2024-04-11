#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+5;

char s[sz];
int a[sz], c[sz];

void solve() {
   int n, p, k;
   ll x, y;
   scanf("%d %d %d", &n, &p, &k);
   scanf("%s", s);
   scanf("%lld %lld", &x, &y);
   for(int i=0; i<n; i++) a[i] = s[i] - '0', c[i] = 1;
   for(int i=n-1; i>=0; i--) {
      int j = i + k;
      if(j < n) a[i] += a[j], c[i] += c[j];
   }
   ll ans = LLONG_MAX, d = 0;
   for(int i=p-1; i<n; i++) {
      ans = min(ans, d + (c[i] - a[i]) * x);
      d += y;
   }
   printf("%lld\n", ans);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}