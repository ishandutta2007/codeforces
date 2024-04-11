#include <bits/stdc++.h>
using namespace std;
typedef double ld;
const int sz = 4e5+5;

typedef pair <ld,ld> point;
#define x first
#define y second

pair <int,int> bb[sz];
point a[sz];
bool ya[sz];

inline ld dis(point a, point b) {
   ld x = a.x - b.x, y = a.y - b.y;
   return x * x + y * y;
}

const ld eps = 1e-10;

bool cmp(pair<point,int> a, pair<point,int> b) {
   if(abs(a.x.x - b.x.x) < eps and abs(a.x.y - b.x.y) < eps) return a.y > b.y;
   if(a.x.y * b.x.y < 0) return a.x.y < b.x.y;
   if(a.x.y <= 0) return a.x.x < b.x.x;
   return a.x.x > b.x.x;
}

pair<point,int> ara[sz];

int main() {
   int n, need;
   cin >> n >> need;
   for(int i=0; i<n; i++) scanf("%d %d", &bb[i].x, &bb[i].y);

   int nc = 0;
   for(int i=0; i<n; i++) {
      if(!bb[i].x and !bb[i].y) {
         need--;
         continue;
      }
      a[nc++] = bb[i];
   }
   n = nc;

   ld lo = 0, hi = 2e5;
   int cc = 32;
   while(cc--) {
      ld r = (lo + hi) / 2;

      int z = 0;
      for(int i=0; i<n; i++) {
         point c = a[i], m = a[i];
         ld val = r * r - dis(m, {0, 0}) / 4;
         if(val < 0) continue;
         ld d = sqrtl(val);
         c.x /= 2;
         c.y /= 2;
         swap(m.x, m.y);
         ld hmm = hypot(m.x, m.y);
         m.y *= -1;
         point a1 = c;
         a1.x += m.x * d / hmm;
         a1.y += m.y * d / hmm;
         ara[z++] = {a1, +(i+1)};
         m.y *= -1;
         m.x *= -1;
         point a2 = c;
         a2.x += m.x * d / hmm;
         a2.y += m.y * d / hmm;
         ara[z++] = {a2, -(i+1)};
      }

      sort(ara, ara+z, cmp);

      for(int i=0; i<z; i++) ara[z+i] = ara[i];
      z <<= 1;

      int cnt = 0, res = 0;
      memset(ya, 0, sizeof ya);
      for(int i=0; i<z; i++) {
         int k = ara[i].y;
         if(k > 0 and !ya[k]) cnt++, ya[k] = 1;
         if(k < 0 and ya[-k]) cnt--, ya[-k] = 0;
         res = max(res, cnt);
      }

      if(res >= need) hi = r;
      else lo = r;
   }
   printf("%.10f\n", (double)lo);
}