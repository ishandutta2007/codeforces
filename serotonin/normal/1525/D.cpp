#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 5005, inf = 1e8;

int n, a[sz], dp[sz];

int fnc(int x) {
   if(x > n) return 0;
   int &w = dp[x];
   if(w >= 0) return w; w = inf;

   if(a[x]) {
      int ans = -x, one = 1, zer = 0;
      for(int i=x+1; i<=n; i++) {
         if(a[i]) ans -= i, one++;
         else ans += i, zer++;
         if(one == zer) {
            w = min(w, ans + fnc(i + 1));
            break;
         }
      }
   }
   else w = min(w, fnc(x + 1));

   stack <int> st;
   for(int i=x, j=0; i<=n; i++) {
      if(a[i]) {
         if(st.empty()) break;
         j += i - st.top(), st.pop();
         w = min(w, j + fnc(i + 1));
      }
      else st.push(i);
   }
   return w;
}

int main() {
   scanf("%d", &n);
   for(int i=1; i<=n; i++) scanf("%d", &a[i]);
   memset(dp, -1, sizeof dp);
   cout << fnc(1);
}