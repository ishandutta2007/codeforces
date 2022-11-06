#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+5;

int a[sz];

void solve() {
   ll w, h, n, x = 1;
   scanf("%lld %lld %lld", &w, &h, &n);
   while(w % 2 == 0) x <<= 1, w >>= 1;
   while(h % 2 == 0) x <<= 1, h >>= 1;
   if(x >= n) puts("YES");
   else puts("NO");
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}