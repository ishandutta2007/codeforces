#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e5+5;

char what(int i) {
   printf("? 1 %d\n", i); fflush(stdout);
   string s;
   cin >> s;
   return s[0];
}

int ask(int l, int r) {
   printf("? 2 %d %d\n", l, r); fflush(stdout);
   int res; cin >> res;
   return res;
}

char ans[sz];

int main() {
   int n;
   cin >> n;

   for(int i=1, j=0; i<=n; i++) {
      if(ask(1, i) > j) ans[i] = what(i), j++;
   }

   for(int i=1; i<=n; i++) {
      if(ans[i]) continue;
      vector <int> pos;
      bool found[26] = {};
      for(int j=i-1; j; j--) {
         int x = ans[j] - 'a';
         if(!found[x]) pos.push_back(j);
         found[x] = 1;
      }
      int lo = 0, hi = pos.size() - 1;
      while(lo < hi) {
         int md = lo + hi >> 1;
         if(ask(pos[md], i) == md + 1) hi = md;
         else lo = md + 1;
      }
      ans[i] = ans[pos[lo]];
   }
   printf("! %s\n", ans + 1);
}