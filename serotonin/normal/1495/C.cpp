#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 505;

char s[sz][sz];

void solve() {
   int n, m;
   scanf("%d %d", &n, &m);
   for(int i=0; i<n; i++) scanf("%s", s[i]);
   int b = 1;
   if(m % 3 == 1) b = 0;

   for(int j=b; j<m; j+=3) {
      for(int i=0; i<n; i++) s[i][j] = 'X';
   }

   if(n == 1) for(int j=0; j<m; j++) s[0][j] = 'X';
   else {
      for(int j=b+3; j<m; j+=3) {
         int r = 0;
         if(s[1][j-1] == 'X' or s[1][j-2] == 'X') r = 1;
         s[r][j-1] = s[r][j-2] = 'X';
      }
   }
   for(int i=0; i<n; i++) puts(s[i]);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}