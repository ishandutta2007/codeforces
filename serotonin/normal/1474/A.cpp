#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1e5+5;

char s[sz];

void solve() {
   int n;
   scanf("%d %s", &n, s);
   int x = 0;
   for(int i=0; i<n; i++) {
      int y = s[i] - '0', z;
      if(!x) z = 1;
      else if(x == 1) {
         if(y) z = 1;
         else z = 0;
      }
      else {
         if(y) z = 0;
         else z = 1;
      }
      printf("%d", z);
      x = y + z;
   }
   puts("");
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}