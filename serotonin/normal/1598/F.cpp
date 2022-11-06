#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 4e5+7;

int n, dp[1<<21], sum[21];
string s[21];
vector <int> upto[21], cnt[21][sz];

int fnc(int m) {
   int &w = dp[m];
   if(w >= 0) return w; w = 0;

   int cum = 0;
   for(int j=0; j<n; j++) if(m & 1 << j) cum += sum[j];
   if(cum < 0) return w;

   for(int j=0; j<n; j++) if(!(m & 1 << j)) {

      int cid = upper_bound(upto[j].begin(), upto[j].end(), cum) - upto[j].begin();

      auto &vec = cnt[j][cum];
      int now = upper_bound(vec.begin(), vec.end(), cid - 1) - vec.begin();

      if(cid == upto[j].size()) now += fnc(m | 1 << j);

      w = max(w, now);
   }
   return w;
}

int main() {
   ios_base::sync_with_stdio(0); cin.tie(0);

   cin >> n;
   for(int i=0; i<n; i++) cin >> s[i];

   for(int i=0; i<n; i++) {
      int &w = sum[i];
      upto[i].resize(s[i].size());
      for(int j=0; j<s[i].size(); j++) {
         char c = s[i][j];
         if(c == '(') w++;
         else w--;
         upto[i][j] = -w;
         if(j) upto[i][j] = max(upto[i][j-1], upto[i][j]);

         if(w <= 0) cnt[i][-w].push_back(j);
      }
   }

   memset(dp, -1, sizeof(dp));
   cout << fnc(0);
}