#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1e6+7;

int a[sz], cnt[sz], cut[sz];

void solve() {
   int n, m;
   scanf("%d", &n);
   m = n << 1;
   for(int i=1; i<=m; i++) scanf("%d", &a[i]);
   sort(a, a+m+1);

   for(int k=1; k<m; k++) {
      vector <pair<int,int>> ans(n);
      ans[0] = {a[m], a[k]}; cut[a[k]]++;
      for(int i=1; i<m; i++) if(i ^ k) cnt[a[i]]++;
      int sum = a[m], yes = 1;
      for(int i=1, j=m-1; i<n; i++, j--) {
         while(cut[a[j]]) cut[a[j]]--, j--;
         int x = a[j], y = sum - x; cnt[x]--;
         if(!cnt[y] or y < 0) {
            yes = 0;
            break;
         }
         cnt[y]--, cut[y]++;
         ans[i] = {x, y}; sum = x;
      }
      for(int i=1; i<m; i++) cnt[a[i]] = cut[a[i]] = 0;
      if(yes) {
         puts("YES");
         printf("%d\n", a[m] + a[k]);
         for(auto [u, v] : ans) printf("%d %d\n", u, v);
         return;
      }
   }
   puts("NO");
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}