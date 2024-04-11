#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e6+7;

char s[sz];
int a[sz], b[sz];

void solve() {
   int n, k;
   scanf("%d %d %s", &n, &k, s);
   for(int i=0; i<n; i++) a[i+1] = s[i] - '0';
   k = min(n, k);
   a[n+1] = b[n+1] = 0;
   while(k--) {
      for(int i=1; i<=n; i++) {
         if(a[i] or a[i-1] + a[i+1] == 1) b[i] = 1;
         else b[i] = 0;
      }
      for(int i=1; i<=n; i++) a[i] = b[i];
   }
   for(int i=1; i<=n; i++) printf("%d", a[i]); puts("");
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}