#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e6+7;

void solve() {
   int a, b, c, x, y;
   scanf("%d %d %d %d %d", &a, &b, &c, &x, &y);
   x -= a, y -= b;
   x = max(x, 0);
   y = max(y, 0);
   puts(x + y <= c ? "YES" : "NO");
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}