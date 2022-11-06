#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 105;

char s[sz][sz], a[sz][sz], b[sz][sz];

void solve() {
   int n, m;
   scanf("%d %d", &n, &m);
   for(int i=0; i<n; i++) scanf("%s", s[i]);

   bool yes = 1;
   for(int i=0; i<n; i++) {
      for(int j=0; j<m; j++) {
         int x = i + j;
         if(x & 1) a[i][j] = 'R';
         else a[i][j] = 'W';
         if(s[i][j] != '.' and a[i][j] != s[i][j]) yes = 0;
      }
   }

   if(yes) {
      puts("YES");
      for(int i=0; i<n; i++) a[i][m] = 0, puts(a[i]);
      return;
   }

   yes = 1;
   for(int i=0; i<n; i++) {
      for(int j=0; j<m; j++) {
         int x = i + j;
         if(~x & 1) a[i][j] = 'R';
         else a[i][j] = 'W';
         if(s[i][j] != '.' and a[i][j] != s[i][j]) yes = 0;
      }
   }

   if(yes) {
      puts("YES");
      for(int i=0; i<n; i++) a[i][m] = 0, puts(a[i]);
      return;
   }

   puts("NO");
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}