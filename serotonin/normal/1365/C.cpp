#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+5;

int a[sz], b[sz], d[sz];

int main()
{
   int n;
   cin >> n;
   map <int,int> mp;
   for(int i=0; i<n; i++) scanf("%d", &a[i]), mp[a[i]] = i, a[i] = i;
   for(int i=0; i<n; i++) scanf("%d", &b[i]), b[i] = mp[b[i]];

   int ans = 0;
   for(int i=n-1; i>=0; i--) {
      int x = a[i] - b[i];
      if(x >= 0) d[x]++, ans = max(ans, d[x]);
   }

   for(int i=0; i<n; i++) {
      int x = a[i] - b[i];
      if(x >= 0) d[x]--;
      else {
         x += n;
         d[x]++;
         ans = max(ans, d[x]);
      }
   }

   printf("%d\n", ans);
}