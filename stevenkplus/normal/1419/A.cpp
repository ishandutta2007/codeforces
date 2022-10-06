#include <bits/stdc++.h>
using namespace std;
int main() {
   int T;
   cin >> T;
   while (T--) {
      int n;
      cin >> n;
      string s;
      cin >> s;
      vector<int> v(n);
      for (int i = 0; i < n; ++i) v[i] = s[i] - '0';

      int ans;
      if (n % 2 == 0) {
         ans = 1;
         for (int i = 1; i < n; i += 2) {
            if (v[i] % 2 == 0) ans = 2;
         }
      } else {
         ans = 2;
         for (int i = 0; i < n; i += 2) {
            if (v[i] % 2 == 1) ans = 1;
         }
      }
      cout << ans << "\n";
   }
}