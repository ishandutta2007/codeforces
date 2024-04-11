#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e5+5;

int main()
{
   int t;
   cin >> t;
   while(t--) {
      int n;
      scanf("%d", &n);

      int two = 0, three = 0;
      while(n % 2 == 0) n >>= 1, two++;
      while(n % 3 == 0) n /= 3, three++;

      if(two > three || n > 1) puts("-1");
      else printf("%d\n", three - two + three);
   }
}