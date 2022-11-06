#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+5;

int a[sz];

void solve() {
   int n;
   cin >> n;
   for(int i=0; i<n; i++) scanf("%d", &a[i]);
   reverse(a, a+n);
   int ans = 0;
   for(int i=1; i<n; i++) {
      if(a[i] < a[i-1]) {
         for(int j=i; j<n; j++) {
            if(a[j] > a[j-1]) break;
            ans = j;
         }
         break;
      }
      ans = i;
   }
   printf("%d\n", n - ans - 1);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}