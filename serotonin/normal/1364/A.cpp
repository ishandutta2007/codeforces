#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+5;

int a[sz];

int main()
{
   int t;
   cin >> t;
   while(t--) {
      int n, x, ans = -1, f = -1;
      scanf("%d %d", &n, &x);
      for(int i=1; i<=n; i++) {
         scanf("%d", &a[i]);
         a[i] += a[i-1];
         a[i] %= x;
         if(a[i]) {
            ans = max(ans, i);
            if(f < 0) f = i;
         }
         else if(f >= 0) ans = max(ans, i - f);
      }
      printf("%d\n", ans);
   }
}