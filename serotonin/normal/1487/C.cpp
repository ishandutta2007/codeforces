#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 105;

int a[sz][sz];

void solve() {
   int n;
   scanf("%d", &n);
   memset(a, 0, sizeof(a));
   for(int i=0, k=(n-1)/2; i<n; i++) {
      for(int t=0, j=i+1; t<k; t++, j++) {
         if(j == n) j = 0;
         a[i][j] = 1, a[j][i] = -1;
      }
   }
   int sum[n] = {};
   for(int i=0; i<n; i++) {
      for(int j=i+1; j<n; j++) {
         printf("%d ", a[i][j]);
         if(a[i][j] > 0) sum[i] += 3;
         else if(a[i][j] < 0) sum[j] += 3;
         else sum[i]++, sum[j]++;
      }
   }
   sort(sum, sum + n);
   assert(sum[0] == sum[n-1]);
   puts("");
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}