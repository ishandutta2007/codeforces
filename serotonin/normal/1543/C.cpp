#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int sz = 2e5+7;

ld v;
const ld eps = 1e-10;

ld go(ld c, ld m, ld p, int d) {
   ld now = p * d;
   if(c == 0) {}
   else if(c < v) {
      if(m > eps) now += c * go(0, m + c / 2, p + c / 2, d + 1);
      else now += c * go(0, 0, p + c, d + 1);
   }
   else {
      if(m > eps) now += c * go(c - v, m + v / 2, p + v / 2, d + 1);
      else now += c * go(c - v, 0, p + v, d + 1);
   }

   if(m == 0) {}
   else if(m < v) {
      if(c > eps) now += m * go(c + m / 2, 0, p + m / 2, d + 1);
      else now += m * go(0, 0, p + m, d + 1);
   }
   else {
      if(c > eps) now += m * go(c + v / 2, m - v, p + v / 2, d + 1);
      else now += m * go(0, m - v, p + v, d + 1);
   }
   return now;
}

void solve() {
   double c, m, p, vv;
   scanf("%lf %lf %lf %lf", &c, &m, &p, &vv); v = vv;
   double ans = go(c, m, p, 1);
   printf("%.15f\n", ans);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}