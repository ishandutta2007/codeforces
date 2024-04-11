#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e5+5;

int a[sz];
ll cum[sz];

int main() {
   int n, m;
   scanf("%d %d", &n, &m);
   for(int i=1; i<=n; i++) scanf("%d", &a[i]);
   sort(a, a + n + 1);
   for(int i=1; i<=n; i++) cum[i] = a[i] + cum[i-1];
   while(m--) {
      int x, y;
      scanf("%d %d", &x, &y);
      printf("%lld\n", cum[n - x + y] - cum[n - x]);
   }
}