#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1e5+5;

int n, cut, a[sz], dp[sz];

void solve() {
   int n;
   scanf("%d", &n);
   for(int i=0; i<n; i++) scanf("%d", &a[i]);
   if(a[0] + a[1] <= a[n-1]) printf("1 2 %d\n", n);
   else puts("-1");
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}