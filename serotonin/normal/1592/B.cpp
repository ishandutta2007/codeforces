#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 4e5+5;

int a[sz], b[sz];

void solve() {
   int n, x;
   scanf("%d %d", &n, &x);
   for(int i=0; i<n; i++) scanf("%d", &a[i]), b[i] = a[i];
   sort(a, a+n);

   for(int i=0; i<n; i++) {
      if(i-x >= 0) continue;
      if(i+x < n) continue;
      if(a[i] == b[i]) continue;
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