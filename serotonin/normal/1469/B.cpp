#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+5;

int a[sz], b[sz];

void solve() {
   int n, m;
   scanf("%d", &n);
   for(int i=1; i<=n; i++) scanf("%d", &a[i]), a[i] += a[i-1];
   scanf("%d", &m);
   for(int i=1; i<=m; i++) scanf("%d", &b[i]), b[i] += b[i-1];

   int x = *max_element(a, a+n+1);
   int y = *max_element(b, b+m+1);
   printf("%d\n", x + y);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}