#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2005;

int a[sz];

int main()
{
   int n, p;
   cin >> n >> p;
   for(int i=0; i<n; i++) scanf("%d", &a[i]);
   sort(a, a+n);

   vector <int> ans;
   for(int x=0; x<sz; x++) {
      bool yes = 1;
      int cnt[n] = {0};
      for(int i=0; i<n; i++) {
         int z = a[i] - x;
         if(z > n-1) yes = 0;
         else cnt[max(0, z)]++;
      }
      for(int i=0, j=0; i<n && yes; i++) {
         j += cnt[i];
         int z = j - i;
         if(z <= 0 || z % p == 0) yes = 0;
      }
      if(yes) ans.push_back(x);
   }

   printf("%d\n", ans.size());
   for(int x : ans) printf("%d ", x);
}