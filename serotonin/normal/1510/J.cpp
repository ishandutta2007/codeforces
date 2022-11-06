#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1e5+7;

typedef pair <int,int> pii;
#define x first
#define y second

char s[sz];
int tot[sz], prad[sz];
vector <int> ans;

void nope() {
   puts("-1");
   exit(0);
}

void add(int x) {
   if(!x) return;
   if(x & 1) ans.push_back(2), x -= 2;
   x >>= 1;
   while(x--) ans.push_back(1);
}

int main() {
   scanf("%s", s);
   int n = strlen(s);

   vector <int> seg;
   for(int i=1, j=1; i<=n; i++) {
      if(s[i] ^ s[i-1]) seg.push_back(j), j = 1;
      else j++;
   }

   vector <pii> sides;
   int zp = seg.size(), k = s[0] == '#' ? 0 : 1;
   for(; k<zp; k+=2) {
      int lhs = k ? seg[k-1] : 0, rhs = k+1 < zp ? seg[k+1] : 0;
      if(k > 1) lhs--;
      if(k < zp - 2) rhs--;
      if(lhs > rhs) sides.emplace_back(lhs - rhs, 0);
      else sides.emplace_back(0, rhs - lhs);
   }

   if(sides.empty()) {
      puts("0");
      return 0;
   }

   int z = sides.size();
   for(int i=1; i<z; i++) {
      auto &lhs = sides[i-1], &rhs = sides[i];
      tot[i] = max(lhs.y, rhs.x);
      int d = lhs.y - rhs.x;
      if(d >= 0) rhs.y += d;
      else prad[i-1] = -d;
   }
   tot[0] = sides[0].x;
   tot[z] = sides.back().y;

   int sum = 0;
   bool one = 0, two = 0;
   for(int i=z; i>=0; i--) {
      sum += prad[i];
      tot[i] += sum;
      one |= tot[i] == 1;
      two |= tot[i] == 0;
   }
   int d = one + (one & two);
   for(int i=z; i>=0; i--) tot[i] += d;

   k = s[0] == '#' ? 0 : 1;
   for(; k<zp; k+=2) {
      int lhs = k ? seg[k-1] : 0, rhs = k+1 < zp ? seg[k+1] : 0;
      if(k > 1) lhs--;
      if(k < zp - 2) rhs--;
      int lcut = tot[k/2], rcut = tot[k/2 + 1];
      int h = seg[k], y = lhs + rhs + h - lcut - rcut;

      if(lcut) {
         if(~lcut & 1 and lcut >= lhs) nope();
         if(lcut & 1 and lcut + 1 >= lhs) nope();
      }
      if(rcut) {
         if(~rcut & 1 and rcut >= rhs) nope();
         if(rcut & 1 and rcut + 1 >= rhs) nope();
      }

      int x = (h + y) >> 1;
      if(x > y or y < h) nope();
      add(lcut);
      ans.push_back(x);
   }
   add(tot[z]);
   printf("%d\n", ans.size());
   for(int x : ans) printf("%d ", x);
}