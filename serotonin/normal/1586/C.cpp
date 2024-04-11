#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1e6+7;

string s[sz];
int ok[sz];

void solve() {
   int n, m;
   cin >> n >> m;
   for(int i=0; i<n; i++) cin >> s[i];

   for(int j=1; j<m; j++) {
      ok[j] = 0;
      for(int i=0; i<n-1; i++) {
         if(s[i][j] == 'X' and s[i+1][j-1] == 'X') ok[j] = 1;
      }
      ok[j] += ok[j-1];
   }

   int q;
   cin >> q;
   while(q--) {
      int l, r;
      cin >> l >> r;
      l--, r--;
      if(l == r) cout << "YES" << '\n';
      else if(ok[r] - ok[l]) cout << "NO" << '\n';
      else cout << "YES" << '\n';
   }
}

int main() {
   ios_base::sync_with_stdio(0); cin.tie(0);
   int t = 1;
//   cin >> t;
   while(t--) solve();
}