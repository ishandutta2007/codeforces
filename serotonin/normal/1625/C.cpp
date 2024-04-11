#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 505;

int n, l;
int a[sz], d[sz], dp[sz][sz];

int fnc(int i, int k) {
   if(i > n) return 0;
   if(i == n) return (l - d[n]) * a[n];
   int &w = dp[i][k];
   if(w >= 0) return w;
   w = fnc(i + 1, k) + (d[i + 1] - d[i]) * a[i];
   for(int j = 1; j <= k; j++) {
      w = min(w, fnc(i + 1 + j, k - j) + (d[i + 1 + j] - d[i]) * a[i]);
      if(i + 1 + j > n) break;
   }
   return w;
}

int main() {
   int k;
   cin >> n >> l >> k; d[n + 1] = l;
   for(int i=1; i<=n; i++) scanf("%d", &d[i]);
   for(int i=1; i<=n; i++) scanf("%d", &a[i]);
   memset(dp, -1, sizeof(dp));
   cout << fnc(1, k);
}