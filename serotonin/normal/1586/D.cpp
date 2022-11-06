#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1e6+7;

int n, ans[sz];

int ask(int x, int y) {
   printf("? ");
   for(int i=1; i<n; i++) printf("%d ", x);
   printf("%d\n", y); fflush(stdout);

   int k;
   cin >> k;
   return k;
}

int main() {
   cin >> n;

   for(int i=n; i; i--) {
      if(i == 1) {
         ans[n] = 1;
         break;
      }
      if(ask(i, 1)) {
         ans[n] = i;
         break;
      }
   }

   for(int i=1; i<=n; i++) {
      if(i == ans[n]) continue;
      if(i < ans[n]) ans[ask(ans[n] + 1 - i, 1)] = i;
      else ans[ask(1, 1 + i - ans[n])] = i;
   }

   printf("!");
   for(int i=1; i<=n; i++) printf(" %d", ans[i]);
   cout << endl;
}