#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 5e5+5;

int a[sz];

void solve() {
   int n, x;
   scanf("%d %d", &n, &x);
   for(int i=0; i<2*n; i++) scanf("%d", &a[i]);
   sort(a, a + n *2);
   for(int i=0; i<n; i++) if(a[i] + x > a[i+n]) {
      puts("NO");
      return;
   }
   puts("YES");
}

int main() {
   int t; cin >> t;
   while(t--) solve();
}