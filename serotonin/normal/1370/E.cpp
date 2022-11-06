#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1e6+5;

char s[sz], t[sz];

int main()
{
   int n;
   cin >> n;
   scanf("%s %s", s, t);

   int ans1 = 0, ans2 = 0, od = 0, ev = 0;
   for(int i=0; i<n; i++) {
      if(s[i] == t[i]) continue;
      if(s[i] == '1') {
         if(ev) ev--;
         else od++;
      }
      else {
         if(od) od--;
         else ev++;
      }
      ans1 = max(ans1, od);
      ans2 = max(ans2, ev);
   }

   if(od || ev) cout << -1;
   else cout << ans1 + ans2;
}