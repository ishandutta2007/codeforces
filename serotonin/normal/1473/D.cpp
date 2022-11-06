#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+5;

int a[sz];
char s[sz];
int pmx[sz], pmn[sz], smx[sz], smn[sz];

void solve() {
   int n, m;
   scanf("%d %d %s", &n, &m, s+1);
   for(int i=1; i<=n; i++) {
      a[i] = a[i-1];
      if(s[i] == '+') a[i]++;
      else a[i]--;
      pmx[i] = max(pmx[i-1], a[i]);
      pmn[i] = min(pmn[i-1], a[i]);
   }
   smx[n] = smn[n] = a[n];
   for(int i=n-1; i; i--) {
      smx[i] = max(smx[i+1], a[i]);
      smn[i] = min(smn[i+1], a[i]);
   }

   while(m--) {
      int l, r;
      scanf("%d %d", &l, &r);
      l--;
      int mx = pmx[l], mn = pmn[l];
      if(r < n) mx = max(mx, a[l] + smx[r+1] - a[r]);
      if(r < n) mn = min(mn, a[l] + smn[r+1] - a[r]);
      printf("%d\n", mx - mn + 1);
   }
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}