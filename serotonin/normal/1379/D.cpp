#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1e5+5;

int hour[sz];

int main() {
   int n, h, m, k;
   cin >> n >> h >> m >> k;
   m >>= 1;
   for(int i=1; i<=n; i++) {
      int mm;
      scanf("%d %d", &mm, &mm);
      if(mm >= m) mm -= m;
      hour[i] = mm;
   }

   int cut = 0;
   map <int,int> mp;
   for(int i=1; i<=n; i++) {
      int mm = hour[i];
      int bad = mm - k + 1;
      if(bad < 0) bad += m, cut++;
      mp[bad]++;
      mp[mm]--;
   }

   int ans = INT_MAX, when = 0;
   for(auto it : mp) {
      cut += it.second;
      if(cut < ans) ans = cut, when = it.first;
   }

   printf("%d %d\n", ans, (when + k) % m);
   for(int i=1; i<=n; i++) {
      int mm = hour[i];
      int bad = mm - k + 1;
      if(bad < 0) bad += m;
      if(bad <= mm) {
         if(bad <= when && when < mm) printf("%d ", i);
      }
      else {
         if(when < mm || when >= bad) printf("%d ", i);
      }
   }
}