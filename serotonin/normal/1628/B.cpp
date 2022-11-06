#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+7;

string s[sz];
bool beg[26][26], tbeg[26][26];

void solve() {
   int n;
   cin >> n;
   for(int i=0; i<n; i++) cin >> s[i];

   for(int i=0; i<n; i++) {
      if(s[i].size() == 1) {
         cout << "YES" << '\n';
         return;
      }
      if(s[i][0] == s[i].back()) {
         cout << "YES" << '\n';
         return;
      }
   }

   memset(beg, 0, sizeof(beg));
   memset(tbeg, 0, sizeof(tbeg));
   set <string> st;
   for(int i=0; i<n; i++) {
      int x = s[i][0] - 'a';
      int y = s[i][1] - 'a';
      if(s[i].size() == 2) {
         if(beg[y][x] or tbeg[y][x]) {
            cout << "YES" << '\n';
            return;
         }
         beg[x][y] = 1;
         continue;
      }
      int z = s[i][2] - 'a';
      string r = s[i];
      reverse(r.begin(), r.end());
      if(beg[z][y] or st.count(r)) {
         cout << "YES" << '\n';
         return;
      }
      st.insert(s[i]);
      tbeg[x][y] = 1;
   }

   cout << "NO" << '\n';
}

int main() {
   ios_base::sync_with_stdio(0); cin.tie(0);
   int t;
   cin >> t;
   while(t--) solve();
}