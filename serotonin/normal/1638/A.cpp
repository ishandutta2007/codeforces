#include<bits/extc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e6+7;

int a[sz];

void solve() {
   int n;
   scanf("%d", &n);
   for(int i=1; i<=n; i++) scanf("%d", &a[i]);
   for(int i=1; i<=n; i++) {
      if(a[i] != i) {
         for(int j=i; j<=n; j++) {
            if(a[j] == i) {
               reverse(a + i, a + j + 1);
               for(int k=1; k<=n; k++) printf("%d ", a[k]);
               puts("");
               return;
            }
         }
      }
   }
   for(int i=1; i<=n; i++) printf("%d ", a[i]);
   puts("");
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}