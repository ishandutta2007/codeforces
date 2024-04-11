#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 5005;

int n, a[sz], dp[sz], cnt[sz];
vector <int> g[sz], vec;
int dpcan[sz][sz];

bool can(int l, int r) {
   if(l > r) return 1;
   int d = l - r + 1;
   if(d & 1) return 0;
   return dpcan[l][r];
}

int fnc(int pref) {     // vec[pref] remains in the end
   int &w = dp[pref];
   if(~w) return w; w = -sz;
   int i = vec[pref];
   if(can(i + 1, n)) w = 1;
   for(int k = pref + 1; k < vec.size(); k++) {
      int j = vec[k];
      if(can(i + 1, j - 1)) w = max(w, 1 + fnc(k));
   }
   return w;
}

void solve() {
   scanf("%d", &n);
   for(int i=1; i<=n; i++) g[i].clear();
   for(int i=1; i<=n; i++) scanf("%d", &a[i]), g[a[i]].push_back(i);

   for(int i=1; i<=n; i++) {
      int mxc = 0;
      memset(cnt, 0, sizeof cnt);
      for(int j=i, k=1; j<=n; j++, k++) {
         mxc = max(mxc, ++cnt[a[j]]);
         dpcan[i][j] = mxc * 2 > k ? 0 : 1;
      }
   }

   int ans = n & 1;
   for(int x = 1; x <= n; x++) {
      vec = g[x];
      memset(dp, -1, sizeof(dp));
      for(int i=0; i<vec.size(); i++) {
         if(can(1, vec[i] - 1)) {
            ans = max(ans, fnc(i));
         }
      }
   }
   printf("%d\n", ans);
}

int main() {
   int t; cin >> t;
   while(t--) solve();
}