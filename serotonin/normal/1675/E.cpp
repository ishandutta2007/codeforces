#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e5+7;

char s[sz];

void solve() {
   int n, k;
   scanf("%d %d", &n, &k);
   scanf("%s", s);

   int wut[27];
   iota(wut, wut + 27, 0);
   
   for(int i=0; i<n; i++) {
      int c = s[i] - 'a';
      int u = c;
      while(wut[u] and k) u--, k--;
      for(int j=0; j<=c; j++) wut[j] = min(wut[j], wut[u]);
   }
   for(int i=0; i<n; i++) printf("%c", 'a' + wut[s[i] - 'a']);
   puts("");
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}