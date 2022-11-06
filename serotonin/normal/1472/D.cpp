#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+5;

int a[sz];

void solve() {
   int n;
   scanf("%d", &n);
   for(int i=0; i<n; i++) scanf("%d", &a[i]);
   sort(a, a+n);
   reverse(a, a+n);
   ll x = 0, y = 0;
   for(int i=0; i<n; i++) {
      if(i % 2 == 0 and a[i] % 2 == 0) x += a[i];
      if(i & 1 and a[i] & 1) y += a[i];
   }
   if(x > y) puts("Alice");
   else if(x < y) puts("Bob");
   else puts("Tie");
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}