#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e6+7;

void solve() {
   int a, b, c, m;
   scanf("%d %d %d %d", &a, &b, &c, &m);
   int mx = a + b + c - 3;

   int d = max({a, b, c});
   int r = a + b + c - d;
   int mn = max(0, d - 1 - r);

   puts(mn <= m and m <= mx ? "YES" : "NO");
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}