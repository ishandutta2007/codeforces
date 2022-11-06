#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1e6+5;

int a[sz], spar[20][sz];
char s[sz];

void build(int n) {
   for(int i=0; i<n; i++) spar[0][i] = a[i];
   for(int j=1; j<20; j++) {
      for(int i=0; i<n; i++) {
         int k = i + (1 << j-1);
         int &w = spar[j][i] = spar[j-1][i];
         if(k < sz) w = max(w, spar[j-1][k]);
      }
   }
}

inline int quer(int l, int r) {
   int h = 31 - __builtin_clz(r - l + 1);
   return max(spar[h][l], spar[h][r+1-(1<<h)]);
}

int main() {
   int n;
   scanf("%d %s", &n, s);

   int zer = -1, one = -1;
   for(int i=0; i<n; i++) {
      int &w = a[i];
      if(s[i] == '?') w = i - min(zer, one);
      else if(s[i] == '1') w = i - zer, one = i;
      else w = i - one, zer = i;
   }

   build(n);

   for(int i=1; i<=n; i++) {
      int ans = 0;
      for(int j=i-1; j<n; j+=i) {
         int lo = j, hi = n-1;
         while(lo < hi && a[lo] < i) {
            int md = lo + hi >> 1;
            if(quer(j, md) >= i) hi = md;
            else lo = md + 1;
         }
         if(a[lo] < i) break;
         j = lo;
         ans++;
      }
      printf("%d ", ans);
   }
}