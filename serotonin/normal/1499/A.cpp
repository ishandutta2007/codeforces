#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 4e5+7;

void solve() {
   int n, k1, k2;
   scanf("%d %d %d", &n, &k1, &k2);
   int w, b;
   scanf("%d %d", &w, &b);

   int x = k1 + k2;
   int y = 2 * n - x;

   if(x / 2 >= w and y / 2 >= b) puts("YES");
   else puts("NO");
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}