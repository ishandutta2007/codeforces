#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e6+5;

int a[sz];

void solve() {
   int n;
   scanf("%d", &n);
   for(int i=0; i<n; i++) scanf("%d", &a[i]);
   sort(a, a+n);
   double ans = 0;
   for(int i=0; i<n-1; i++) ans += a[i];
   printf("%.10f\n", ans / (n - 1) + a[n-1]);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}