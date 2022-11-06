#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e5+5;

int l[sz], r[sz];
char a[sz], b[sz];

void solve() {
   int n;
   scanf("%d %s %s", &n, a + 1, b + 1);

   string s, t;
   for(int i=1; i<=n; i++) if(a[i] != 'b') s += a[i];
   for(int i=1; i<=n; i++) if(b[i] != 'b') t += b[i];

   if(s != t) {
      puts("NO");
      return;
   }

   int k = 0;
   for(int i=1, j=0; i<=n; i++) {
      if(a[i] == 'b') l[++k] = j + 1;
      else if(a[i] == 'c') j = i;
   }

   for(int i=n, j=n+1; i; i--) {
      if(a[i] == 'b') r[k--] = j - 1;
      else if(a[i] == 'a') j = i;
   }

   for(int i=1, k=1; i<=n; i++) {
      if(b[i] == 'b') {
         if(l[k] > i or r[k] < i) {
            puts("NO");
            return;
         }
         k++;
      }
   }
   puts("YES");
}

int main() {
   int t; cin >> t;
   while(t--) solve();
}