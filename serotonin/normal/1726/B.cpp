#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1e6+7;

int a[sz];

void solve() {
   int n, m;
   scanf("%d %d", &n, &m);
   if(n & 1) {
      if(m >= n) {
         puts("Yes");
         for(int i=1; i<n; i++) printf("1 "), m--;
         printf("%d\n", m);
      }
      else puts("No");
   }
   else {
      if(~m & 1 and m >= n) {
         puts("Yes");
         vector <int> ans;
         m /= 2, n /= 2;
         for(int i=1; i<n; i++) printf("1 "), m--;
         printf("%d ", m);
         for(int i=1; i<n; i++) printf("1 ");
         printf("%d ", m);
         puts("");
      }
      else puts("No");
   }
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}