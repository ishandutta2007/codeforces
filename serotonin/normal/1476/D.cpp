#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+5;

char s[sz];
int lhs[sz], rhs[sz];

void solve() {
   int n;
   scanf("%d %s", &n, s);
   for(int i=0, j=0; i<n; i++) {
      if(i and s[i] != s[i-1]) j++;
      else j = 1;
      lhs[i] = j;
   }
   for(int i=n-1, j=0; i>=0; i--) {
      if(i<n-1 and s[i] != s[i+1]) j++;
      else j = 1;
      rhs[i] = j;
   }
   for(int i=0; i<=n; i++) {
      int ans = 1;
      if(i<n and s[i] == 'R') ans += rhs[i];
      if(i and s[i-1] == 'L') ans += lhs[i-1];
      printf("%d ", ans);
   }
   puts("");
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}