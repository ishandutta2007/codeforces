#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1e5+5;

void solve() {
   int n, m;
   scanf("%d %d", &n, &m);
   if(n == 1 and m == 1) {
      puts("0");
      return;
   }
   int ans = n + m - 2;
   ans += min(n, m);
   printf("%d\n", ans);
}

int main() {
   int t; cin >> t;
   while(t--) solve();
}