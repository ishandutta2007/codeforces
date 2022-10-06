#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main() {
   int T;
   cin >> T;
   while (T--) {
      int n, x;
      cin >> n >> x;
      vector<int> v(n);
      for (int &i: v) cin >> i;
      bool allSame = true;
      int ans = 2;
      for (int i: v) {
         if (i == x) {
            ans = 1;
         } else {
            allSame = false;
         }
      }
      int sum = 0;
      for (int i: v) sum += i;
      if (sum == x * n) ans = 1;

      if (allSame) ans = 0;
      cout << ans << "\n";
   }
}