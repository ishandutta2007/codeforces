#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+5;

void solve() {
   int n;
   scanf("%d", &n);
   int a[] = {6, 10, 14, 15, 21, 22, 26, 33};
   for(int i=0; i<8; i++) {
      for(int j=i+1; j<8; j++) {
         for(int k=j+1; k<8; k++) {
            int x = n - a[i] - a[j] - a[k];
            if(x > 0 && x != a[i] &&  x != a[j] &&  x != a[k]) {
               puts("YES");
               printf("%d %d %d %d\n", x, a[i], a[j], a[k]);
               return;
            }
         }
      }
   }
   puts("NO");
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}