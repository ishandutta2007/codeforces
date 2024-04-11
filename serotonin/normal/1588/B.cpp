#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e6+7;

int a[sz], b[sz];

ll fnc(ll x) {
   return x * (x - 1) / 2;
}

ll ask(int l, int r) {
   printf("? %d %d\n", l, r);
   fflush(stdout);
   ll x;
   scanf("%lld", &x);
   return x;
}

void ans(int i, int j, int k) {
   printf("! %d %d %d\n", i, j, k);
   fflush(stdout);
}

void solve() {
   int n;
   cin >> n;

   int lo = 2, hi = n - 2;
   while(lo < hi) {
      int md = lo + hi >> 1;
      if(ask(1, md) > 0) hi = md;
      else lo = md + 1;
   }

   int i = lo - 1;
   ll tot = ask(i, n);
   int dx = tot - ask(i + 1, n) + 1;

   int j = i + dx;
   int dy = tot - fnc(dx) - ask(j + 1, n);
   ans(i, j, j + dy);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}