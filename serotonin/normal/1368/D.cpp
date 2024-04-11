#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+5;

ll cnt[69];

int main()
{
   int n;
   cin >> n;
   while(n--) {
      ll x;
      scanf("%lld", &x);
      int i=0;
      while(x) {
         if(x & 1) cnt[i]++;
         x >>= 1;
         i++;
      }
   }

   ll ans = 0;
   while(1) {
      ll now = 0;
      for(int i=69; i>=0; i--) {
         if(cnt[i]) {
            now |= 1LL << i;
            cnt[i]--;
         }
      }
      if(!now) break;
      ans += now * now;
   }

   cout << ans;
}