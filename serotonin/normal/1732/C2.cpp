#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e6+5, magic = 39;

int a[sz], xcum[sz];
ll cum[sz];

int rhs[sz], lhs[sz];

ll fnc(int l, int r) {
   ll ans = cum[r] - cum[l - 1];
   ans -= xcum[r] ^ xcum[l - 1];
   return ans;
}

void solve() {
   int n, q;
   scanf("%d %d", &n, &q);
   for(int i=1; i<=n; i++) scanf("%d", &a[i]);
   
   for(int i=1; i<=n; i++) xcum[i] = a[i] ^ xcum[i - 1];
   for(int i=1; i<=n; i++) cum[i] = a[i] + cum[i - 1];

   for(int i=1; i<=n; i++) {
      if(a[i-1]) lhs[i] = i-1;
      else lhs[i] = lhs[i-1];
   }
   rhs[n] = 0;
   for(int i=n-1; i; i--) {
      if(a[i+1]) rhs[i] = i+1;
      else rhs[i] = rhs[i+1];
   }

   while(q--) {
      int l, r;
      scanf("%d %d", &l, &r);
      
      ll ans = fnc(l, r);

      if(!ans) {
         printf("%d %d\n", l, l);
         continue;
      }

      vector <int> lidk;
      for(int i = a[l] ? l : rhs[l]; ; ) {
         if(i > r) break;
         lidk.push_back(i);
         if(lidk.size() > magic or !rhs[i]) break;
         i = rhs[i];
      }
            
      vector <int> ridk;
      for(int i = a[r] ? r : lhs[r]; ; ) {
         if(i < l) break;
         ridk.push_back(i);
         if(ridk.size() > magic or !lhs[i]) break;
         i = lhs[i];
      }

      pair <int,int> res = {r - l, l};

      for(int x : lidk) {
         for(int y : ridk) {
            if(x > y) swap(x, y);
            if(fnc(x, y) == ans) {
               res = min(res, make_pair(y - x, x));
            }
         }
      }
         
      printf("%d %d\n", res.second, res.second + res.first);
   }
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}