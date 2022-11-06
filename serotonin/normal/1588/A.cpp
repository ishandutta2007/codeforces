#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e6+7;

int a[sz], b[sz];

void solve() {
   int n;
   scanf("%d", &n);
   for(int i=0; i<n; i++) scanf("%d", &a[i]);
   for(int i=0; i<n; i++) scanf("%d", &b[i]);
   sort(a, a+n);
   sort(b, b+n);
   for(int i=0; i<n; i++) {
      if(a[i] == b[i] or a[i] + 1 == b[i]) continue;
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