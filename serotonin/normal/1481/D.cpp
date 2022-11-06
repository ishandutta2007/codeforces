#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1005;

char s[sz][sz];

void fnc(int ain, int i, int aout, int m) {
   if(m % 4) {
      int a[] = {ain, i+1, aout, i+1};
      for(int k=0, j=0; k<=m; k++, j++) {
         if(j == 4) j = 0;
         printf("%d ", a[j]);
      }
   }
   else {
      int x = m >> 1;
      for(int k=0; k<x; k++) {
         if(k & 1) printf("%d ", aout);
         else printf("%d ", i+1);
      }
      for(int k=0; k<x; k++) {
         if(k & 1) printf("%d ", ain);
         else printf("%d ", i+1);
      }
      printf("%d", i+1);
   }
   puts("");
}

void solve() {
   int n, m;
   scanf("%d %d", &n, &m);
   for(int i=0; i<n; i++) scanf("%s", s[i]);

   if(m & 1) {
      puts("YES");
      for(int k=0; k<=m; k++) {
         if(k & 1) printf("1 ");
         else printf("2 ");
      }
      puts("");
      return;
   }

   for(int i=0; i<n; i++) {
      for(int j=i+1; j<n; j++) {
         if(s[i][j] == s[j][i]) {
            puts("YES");
            for(int k=0; k<=m; k++) {
               if(k & 1) printf("%d ", i+1);
               else printf("%d ", j+1);
            }
            puts("");
            return;
         }
      }
   }

   if(n == 2) {
      puts("NO");
      return;
   }

   puts("YES");
   for(int i=0; i<n; i++) {
      int ain = 0, bin = 0, aout = 0, bout = 0;
      for(int j=0; j<n; j++) {
         if(s[i][j] == 'a') aout = j + 1;
         if(s[i][j] == 'b') bout = j + 1;
      }
      for(int j=0; j<n; j++) {
         if(s[j][i] == 'a') ain = j + 1;
         if(s[j][i] == 'b') bin = j + 1;
      }
      if(ain and aout) {
         fnc(ain, i, aout, m);
         return;
      }
      if(bin and bout) {
         fnc(bin, i, bout, m);
         return;
      }
   }
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}