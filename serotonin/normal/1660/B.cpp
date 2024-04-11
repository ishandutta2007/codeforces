#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e6+7;

int a[sz];

void solve() {
   int n;
   scanf("%d", &n);
   for(int i=0; i<n; i++) scanf("%d", &a[i]);
   sort(a, a+n);
   if(n == 1) {
      if(a[0] == 1) puts("yes");
      else puts("no");
   }
   else if(a[n-1] > a[n-2] + 1) puts("no");
   else puts("yes");
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}