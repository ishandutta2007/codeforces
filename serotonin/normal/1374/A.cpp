#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e5+5;

int main()
{
   int t;
   cin >> t;
   while(t--) {
      int x, y, n;
      scanf("%d %d %d", &x, &y, &n);
      int ans = (n / x) * x + y;
      if(ans > n) ans -= x;
      printf("%d\n", ans);
   }
}