#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+5;

void solve()
{
   int n, x, m;
   scanf("%d %d %d", &n, &x, &m);

   int l = x, r = x;
   while(m--) {
      int a, b;
      scanf("%d %d", &a, &b);

      int rx = max(a, l), ry = min(b, r);
      if(rx <= ry) l = min(l, a), r = max(r, b);
   }

   printf("%d\n", r - l + 1);
}

int main()
{
   int t = 1;
   cin >> t;
   while(t--) solve();
}