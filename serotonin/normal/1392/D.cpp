#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e5+7;

char s[sz];

void solve() {
   int n;
   scanf("%d %s", &n, s);
   int j=1;
   vector <int> v;
   for(int i=1; i<n; i++) {
      if(s[i] == s[i-1]) j++;
      else {
         v.push_back(j);
         j = 1;
      }
   }
   if(j) v.push_back(j);
   if(s[0] == s[n-1] && v.size() > 1) {
      v[0] += v.back();
      v.pop_back();
   }

   int ans = 0;
   for(int x : v) ans += x / 3;
   if(v.size() == 1) {
      ans = 1 + (v[0] - 1) / 3;
   }
   printf("%d\n", ans);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}