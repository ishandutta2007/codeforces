#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e5+7;

void solve() {
   int n, k, ans = 0;
   scanf("%d %d", &n, &k);
   for(int i=0; i<n; i++) {
      if(i) printf("%d\n", (i - 1) ^ i);
      else puts("0");
      fflush(stdout);
      int r;
      scanf("%d", &r);
      if(r < 0) exit(0);
      if(r) break;
   }
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}