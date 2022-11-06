#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 4e6+5;

int a[sz];

void solve() {
   int n, k;
   scanf("%d %d", &n, &k);
   for(int i=0; i<n; i++) scanf("%d", &a[i]);
   for(int i=0; i<n; i++) {
      int x = min(a[i], k);
      a[i] -= x;
      k -= x;
      a[n-1] += x;
      printf("%d ", a[i]);
   }
   puts("");
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}