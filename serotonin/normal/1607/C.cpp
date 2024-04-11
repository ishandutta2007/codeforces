#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+7;

int a[sz];

void solve() {
   int n;
   scanf("%d", &n);
   for(int i=0; i<n; i++) scanf("%d", &a[i]);
   sort(a, a+n);

   if(n == 1) printf("%d\n", a[0]);
   else {
      int ans = a[0];
      for(int i=1; i<n; i++) ans = max(ans, a[i] - a[i-1]);
      printf("%d\n", ans);
   }
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}