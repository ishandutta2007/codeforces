#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 4e5+7;

int a[sz], two[sz], sgn[sz], lhs[sz];

void solve() {
   int n;
   scanf("%d", &n);
   for(int i=1; i<=n; i++) scanf("%d", &a[i]);

   for(int i=1; i<=n; i++) two[i] = two[i-1] + (abs(a[i]) == 2);
   for(int i=1; i<=n; i++) sgn[i] = sgn[i-1] + (a[i] < 0), sgn[i] &= 1;
   for(int i=1; i<=n; i++) lhs[i] = a[i] < 0 ? i : lhs[i-1];

   vector <int> zero;
   for(int i=1; i<=n; i++) if(!a[i]) zero.push_back(i);
   zero.push_back(n + 1);

   tuple <int,int,int> ans = {0, n, 0};
   for(int i=1; i<=n; i++) {
      if(!a[i]) continue;
      int r = *lower_bound(zero.begin(), zero.end(), i) - 1;
      if(sgn[r] == sgn[i - 1]) {
         ans = max(ans, {two[r] - two[i - 1], i - 1, n - r});
      }
      else {
         int j = lhs[r] - 1;
         if(j < i) continue;
         ans = max(ans, {two[j] - two[i - 1], i - 1, n - j});
      }
   }
   printf("%d %d\n", get<1>(ans), get<2>(ans));
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}