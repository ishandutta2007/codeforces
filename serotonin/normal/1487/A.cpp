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
   printf("%d\n", n - (upper_bound(a, a+n, a[0]) - a));
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}