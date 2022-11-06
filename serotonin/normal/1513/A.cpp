#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e6+7;

int a[sz];

void solve() {
   int n, k;
   scanf("%d %d", &n, &k);
   int x = (n - 1) >> 1;
   if(k > x) {
      puts("-1");
      return;
   }
   int y = n;
   for(int i=0; i<n; i++) a[i] = 0;
   for(int i=1; i<=k*2; i+=2) a[i] = y--;
   for(int i=0; i<n; i++) if(!a[i]) a[i] = y--;
   for(int i=0; i<n; i++) printf("%d ", a[i]);
   puts("");
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}