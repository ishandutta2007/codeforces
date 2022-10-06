#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main() {
   int n;
   cin >> n;
   vector<int> v(n);
   for (int &i: v) cin >> i;
   sort(v.begin(), v.end());
   int lo = 0;
   int hi = (n - 1) / 2;

   auto can = [&](int len) -> bool {
      for (int i = 0; i < len; ++i) {
         if (v[i] >= v[n - len - 1 + i]) return false;
      }
      return true;
   };
   while (lo < hi) {
      int mid = (lo + hi + 1) / 2;
      if (can(mid)) lo = mid;
      else hi = mid - 1;
   }
   cout << lo << "\n";
   for (int i = 0; i < n; ++i) {
      int val;
      if (i < 2 * lo + 1) {
         if (i % 2 == 0) {
            val = v[n - (lo + 1) + i / 2];
         } else {
            val = v[i / 2];
         }
      } else {
         int j = i - (2 * lo + 1);
         val = v[j + lo];
      }
      cout << val << " ";
   }
   cout << "\n";
}