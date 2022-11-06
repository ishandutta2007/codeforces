#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e5+5;

char a[sz], b[sz];

void solve() {
   int n, m, k;
   scanf("%d %d %d", &n, &m, &k);
   scanf("%s %s", a, b);
   sort(a, a + n);
   sort(b, b + m);
   reverse(a, a + n);
   reverse(b, b + m);
   int i = n - 1, j = m - 1, sem = 0;
   while(i >= 0 and j >= 0) {
      if(sem == -k) {
         sem = 1;
         printf("%c", a[i--]);
      }
      else if(sem == k) {
         sem = -1;
         printf("%c", b[j--]);
      }
      else if(a[i] < b[j]) {
         sem = max(1, sem + 1);
         printf("%c", a[i--]);
      }
      else {
         sem = min(-1, sem - 1);
         printf("%c", b[j--]);
      }
   }
   puts("");
}

int main() {
   int t; 
   cin >> t;
   while(t--) solve();
}