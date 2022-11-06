#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e6+7;

char s[55][55];

void solve() {
   int n, k;
   scanf("%d %d", &n, &k);
   int x = (n + 1) / 2;
   if(x < k) {
      puts("-1");
      return;
   }
   for(int i=0; i<n; i++) {
      for(int j=0; j<n; j++) {
         s[i][j] = '.';
      }
   }
   for(int i=0; i<n and k; i+=2, k--) {
      s[i][i] = 'R';
   }
   for(int i=0; i<n; i++) {
      s[i][n] = 0;
      puts(s[i]);
   }
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}