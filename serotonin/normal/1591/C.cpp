#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 5e5+5;

int k;

ll fnc(vector <int> a) {
   ll ans = 0;
   if(a.empty()) return 0;
   reverse(a.begin(), a.end());
   for(int i=0; i<a.size(); i+=k) {
      ans += a[i];
   }
   return ans;
}

void solve() {
   int n;
   scanf("%d %d", &n, &k);
   vector <int> pos, neg;
   for(int i=0, x; i<n; i++) {
      scanf("%d", &x);
      if(x > 0) pos.push_back(x);
      else if(x < 0) neg.push_back(-x);
   }
   if(pos.empty() and neg.empty()) {
      puts("0");
      return;
   }
   sort(pos.begin(), pos.end());
   sort(neg.begin(), neg.end());

   ll ans = fnc(pos) + fnc(neg);
   ans <<= 1;
   if(pos.empty()) ans -= neg.back();
   else if(neg.empty()) ans -= pos.back();
   else ans -= max(pos.back(), neg.back());
   printf("%lld\n", ans);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}