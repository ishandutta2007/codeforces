#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 53;

int a[sz];

int main() {
   int n, q;
   scanf("%d %d", &n, &q);
   for(int i=1; i<=n; i++) {
      int x;
      scanf("%d", &x);
      if(!a[x]) a[x] = i;
   }
   while(q--) {
      int x;
      scanf("%d", &x);
      int z = a[x]; a[x] = 0;
      for(int i=1; i<sz; i++) if(a[i] < z) a[i]++;
      printf("%d ", z);
   }
}