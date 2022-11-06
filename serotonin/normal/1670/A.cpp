#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+7;

int a[sz];

void solve() {
   int n;
   scanf("%d", &n);
   int c = 0;
   for(int i=0; i<n; i++) scanf("%d", &a[i]), c += a[i] > 0;
   c = n - c;
   for(int i=0; i<c; i++) a[i] = -abs(a[i]);
   for(int i=c; i<n; i++) a[i] = abs(a[i]);

   for(int i=1; i<n; i++) if(a[i] < a[i-1]) {
      puts("NO");
      return;
   }
   puts("YES");
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}