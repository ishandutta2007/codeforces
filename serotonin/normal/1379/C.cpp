#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+5;

typedef pair <ll, ll> pii;
#define x first
#define y second

pii p[sz];
ll cum[sz];

void solve() {
   int n, m;
   scanf("%d %d", &m, &n);
   for(int i=1; i<=n; i++) scanf("%lld %lld", &p[i].x, &p[i].y);
   sort(p+1, p+n+1);
   ll ans = 0;
   for(int i=1; i<=n; i++) cum[i] = cum[i-1] + p[i].x;
   if(m <= n) ans = cum[n] - cum[n-m];
   for(int i=1; i<=n; i++) {
      ll j = upper_bound(p, p+n+1, make_pair(p[i].y, -1LL)) - p - 1;
      ll now = cum[n] - cum[j];
      ll c = n - j;
      if(c >= m) continue;
      c = m - c;
      if(j >= i) now += p[i].x, c--;
      now += c * p[i].y;
      ans = max(ans, now);
   }
   printf("%lld\n", ans);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}