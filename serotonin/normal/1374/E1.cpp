#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e5+5;

int main()
{
   int n, k;
   cin >> n >> k;
   vector <int> both, a, b;
   for(int i=0; i<n; i++) {
      int v, x, y;
      scanf("%d %d %d", &v, &x, &y);
      if(x && y) both.push_back(v);
      else if(x) a.push_back(v);
      else if(y) b.push_back(v);
   }
   sort(a.begin(), a.end());
   sort(b.begin(), b.end());
   for(int i=0; i<min(a.size(), b.size()); i++) {
      both.push_back(a[i] + b[i]);
   }
   sort(both.begin(), both.end());

   if(both.size() < k) puts("-1");
   else {
      ll ans = 0;
      for(int i=0; i<k; i++) ans += both[i];
      printf("%lld\n", ans);
   }
}