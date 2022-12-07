#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1005;

set <int> st[sz];
char s[sz][sz];

void solve() {
   int n;
   scanf("%d", &n);
   for(int i=1; i<=n; i++) scanf("%s", s[i] + 1);

   for(int i=1; i<=n; i++) st[i].clear(), st[i].insert(i);

   for(int i=1; i<=n; i++) {
      for(int j=1; j<=n; j++) {
         if(s[i][j] == '1') {
            st[j].insert(i);
         }
      }
   }

   for(int i=1; i<=n; i++) {
      printf("%d", st[i].size());
      for(int x : st[i]) printf(" %d", x);
      puts("");
   }
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}