#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e5+5;

int ask(int l, int r) {
   cout << "? " << l << " " << r << endl;
   int p;
   cin >> p;
   return p;
}

void out(int x) {
   cout << "! " << x << endl;
   exit(0);
}

void lhs(int n) {
   int lo = 1, hi = n - 1;
   while(lo < hi) {
      int md = lo + hi + 1 >> 1;
      if(ask(md, n) == n) lo = md;
      else hi = md - 1;
   }
   out(lo);
}

void rhs(int b, int n) {
   int lo = b + 1, hi = n;
   while(lo < hi) {
      int md = lo + hi >> 1;
      if(ask(b, md) == b) hi = md;
      else lo = md + 1;
   }
   out(lo);
}

int main() {
   int n;
   cin >> n;
   if(n == 1) out(1);

   int m = ask(1, n);
   if(n == 2) {
      if(m == 1) out(2);
      else out(1);
   }

   if(m == n) lhs(m);
   if(m == 1) rhs(m, n);

   int l = ask(1, m);
   if(l == m) lhs(m);
   else rhs(m, n);
}