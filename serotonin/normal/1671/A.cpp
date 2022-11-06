#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e6+7;

char s[sz];

void solve() {
   scanf("%s", s);
   int big = sz, j = 1;
   for(int i=1; s[i]; i++) {
      if(s[i] == s[i-1]) j++;
      else {
         big = min(big, j);
         j = 1;
      }
   }
   big = min(big, j);
   puts(big == 1 ? "NO" : "YES");
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}