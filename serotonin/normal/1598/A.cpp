#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e6+5;

char s[2][sz];

void solve() {
   int n;
   scanf("%d", &n);
   scanf("%s %s", s[0], s[1]);

   for(int i=0; i<n; i++) if(s[0][i] == s[1][i] and s[0][i] == '1') {
      puts("NO");
      return;
   }

   puts("YES");
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}