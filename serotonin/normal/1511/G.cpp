#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 4e5+5;

int a[sz], spar[18][sz];

int main() {
   int n, m, q;
   cin >> n >> m;
   while(n--) {
      scanf("%d", &q);
      a[q] ^= 1;
   }
   for(int i=m; i; i--) a[i] ^= a[i+1];
   for(int h=1; h<18; h++) {
      for(int i=1, j=1<<h, k=j>>1; i<=m; i++) {
         spar[h][i] = spar[h-1][i] ^ spar[h-1][i+k];
         if(a[i+j] ^ a[i+k]) spar[h][i] ^= k;
      }
   }
   cin >> q;
   while(q--) {
      int l, r, ans = 0;
      scanf("%d %d", &l, &r); r++;
      for(int h=17, j=1<<h; h; h--, j>>=1) {
         if(l+j > r) continue;
         ans ^= spar[h][l]; l += j;
         if(a[l] ^ a[r]) ans ^= j;
      }
      printf("%c", ans ? 'A' : 'B');
   }
}