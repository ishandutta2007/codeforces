#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+5;

int n, q;
char s[sz];

int fnc(int i) {
   if(i >= n) return 0;
   if(i < 2) return 0;
   return s[i-2] == 'a' and s[i-1] == 'b' and s[i] == 'c';
}

void solve() {
   scanf("%d %d", &n, &q);
   scanf("%s", s);
   int ans = 0;
   for(int i=2; i<n; i++) {
      ans += fnc(i);
   }
   while(q--) {
      int x; char c;
      scanf("%d %c", &x, &c); x--;
      ans -= fnc(x), ans -= fnc(x + 1), ans -= fnc(x + 2);
      s[x] = c;
      ans += fnc(x), ans += fnc(x + 1), ans += fnc(x + 2);
      printf("%d\n", ans);
   }
}

int main() {
   int t = 1;
   // cin >> t;
   while(t--) solve();
}