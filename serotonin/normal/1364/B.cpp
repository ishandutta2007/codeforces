#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+5;

int a[sz], ans[sz];

int main()
{
   int t;
   cin >> t;
   while(t--) {
      int n, k = 1;
      scanf("%d", &n);
      for(int i=1; i<=n; i++) scanf("%d", &a[i]);
      bool d = a[1] > a[2];
      ans[0] = a[1];
      for(int i=2; i<=n; i++) {
         bool dik = a[i] > a[i-1];
         if(d ^ dik) ans[k++] = a[i];
         else ans[k-1] = a[i];
         d = dik;
      }
      printf("%d\n", k);
      for(int i=0; i<k; i++) printf("%d ", ans[i]);
      puts("");
   }
}