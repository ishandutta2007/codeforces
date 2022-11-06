#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 5e5+5;

int main() {
   int t;
   cin >> t;
   while(t--) {
      int n;
      scanf("%d", &n);
      int v = 31 - __builtin_clz(n);
      printf("%d\n", (1 << v) - 1);
   }
}