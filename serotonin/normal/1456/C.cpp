#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 5e5+5;

int a[sz], d[sz];
ll cut[sz];

int main() {
   int n, k;
   cin >> n >> k; k++;
   for(int i=0; i<n; i++) scanf("%d", &a[i]);
   sort(a, a+n);

   ll sum = 0;
   for(int i=0, j=0, r=k; i<n; i++) {
      if(i == r) r += k, j++;
      d[i+1] = j+1;
      sum += cut[i] = (ll) a[i] * j;
   }

   ll ans = sum, cum = 0;
   for(int i=n-1; i>=0; i--) {
      sum += cum - cut[i];
      cum += a[i];
      ans = max(ans, sum + cum * d[i]);
   }
   cout << ans;
}