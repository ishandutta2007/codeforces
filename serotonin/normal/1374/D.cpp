#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e5+5;

int a[sz];

int main()
{
   int t;
   cin >> t;
   while(t--) {
      int n, k;
      scanf("%d %d", &n, &k);
      map <int,int> mp;
      for(int i=0; i<n; i++) {
         scanf("%d", &a[i]);
         a[i] %= k;
         if(a[i]) a[i] = k - a[i], mp[a[i]]++;
      }
      ll big = 0;
      for(auto it : mp) {
         ll v = it.first, c = it.second;
         big = max(big, v + k * (c - 1));
      }
      if(big) big++;
      printf("%lld\n", big);
   }
}