#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2005;

int d[sz];
char s[sz][sz];

void solve() {
   int n;
   scanf("%d", &n);
   for(int i=0; i<n; i++) scanf("%s", s[i]);

   int sum = 0;
   for(int i=0; i<n; i++) d[i] = 0;
   for(int i=0; i<n; i++) {
      for(int j=0; j<n; j++) {
         int x = i - j;
         if(x < 0) x += n;
         d[x] += s[i][j] == '1' ? -1 : 1;
         sum += s[i][j] == '1';
      }
   }
   int ans = INT_MAX;
   for(int i=0; i<n; i++) ans = min(ans, d[i]);
   printf("%d\n", ans + sum);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}