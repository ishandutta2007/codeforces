#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 5e5+5;

int a[sz];

void solve() {
   int n;
   cin >> n;
   for(int i=0; i<n; i++) scanf("%d", &a[i]);

   int ans = 0;
   for(int i=n-1, j=n-1; i>=0; i--) {
      if(a[i] > a[j]) ans++, j = i;
   }
   printf("%d\n", ans);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}