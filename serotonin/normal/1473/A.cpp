#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+5;

void solve() {
   int n, d;
   scanf("%d %d", &n, &d);
   vector <int> a(n);
   for(int i=0; i<n; i++) scanf("%d", &a[i]);
   sort(a.begin(), a.end());
   int x = 0;
   for(int i=0; i<n; i++) x = max(x, min(a[i], a[0] + a[1]));
   if(x <= d) puts("YES");
   else puts("NO");
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}