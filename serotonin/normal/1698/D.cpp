#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e6+7;

int a[sz];

int query(int l, int r) {
   printf("? %d %d\n", l, r); fflush(stdout);
   int d = r - l + 1, res = d;
   for(int i=0, j; i<d; i++) {
      scanf("%d", &j);
      if(j < 0) exit(0);
      if(l <= j and j <= r) continue;
      res--;
   }
   return res;
}

void solve() {
   int n;
   scanf("%d", &n);
   if(n < 0) exit(0);
   int lo = 1, hi = n;
   while(lo < hi) {
      int md = lo + hi >> 1;
      if(query(lo, md) & 1) hi = md;
      else lo = md + 1;
   }
   printf("! %d\n", lo); fflush(stdout);
}

int main() {
   int t; cin >> t;
   while(t--) solve();
}