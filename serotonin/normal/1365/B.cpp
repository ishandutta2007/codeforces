#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+5;

int a[sz], b[sz];

int main()
{
   int t;
   cin >> t;
   while(t--) {
      int n;
      cin >> n;
      for(int i=0; i<n; i++) scanf("%d", &a[i]);
      for(int i=0; i<n; i++) scanf("%d", &b[i]);

      sort(b, b+n);
      if(b[0] == b[n-1]) {
         for(int i=0; i<n; i++) b[i] = a[i];
         sort(b, b+n);
         bool no = 0;
         for(int i=0; i<n; i++) if(b[i] ^ a[i]) no = 1;
         if(no) puts("No");
         else puts("Yes");
      }
      else puts("Yes");
   }
}