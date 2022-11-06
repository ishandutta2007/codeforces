#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+5;

void solve()
{
   int n, m, a[69] = {}, b[69] = {};
   scanf("%d %d", &n, &m);
   for(int i=0; i<n; i++) {
      for(int j=0; j<m; j++) {
         int x;
         scanf("%d", &x);
         if(x) a[i+j]++;
         else b[i+j]++;
      }
   }

   int ans = 0;
   for(int i=0, j=n+m-2; i<j; i++, j--) {
      ans += min(a[i]+a[j], b[i]+b[j]);
   }
   printf("%d\n", ans);
}

int main()
{
   int t = 1;
   cin >> t;
   while(t--) solve();
}