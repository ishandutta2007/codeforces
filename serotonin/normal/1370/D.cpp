#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e5+5;

int a[sz];

int main()
{
   int n, k;
   cin >> n >> k;
   for(int i=0; i<n; i++) scanf("%d", &a[i]);

   int lo = 1, hi = 1e9;
   while(lo < hi) {
      int md = lo + hi >> 1;

      int tot = 0;
      vector <int> segs;
      for(int i=0; i<n; i++) {
         int b = i;
         for(; i<n; i++) {
            if(a[i] > md) break;
         }
         int r = i - b;
         if(r) {
            segs.push_back(r);
            tot += (r & 1) ? r : r-1;
         }
      }

      int ans = tot + segs.size() - 1;
      if(a[0] > md || segs[0] % 2 == 0) ans++;
      if(a[n-1] > md || segs.back() % 2 == 0) ans++;

      if(ans >= k) hi = md;
      else lo = md + 1;
   }
   cout << lo;
}