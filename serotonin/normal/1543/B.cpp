#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e5+7;

int a[sz];

void solve() {
   int n; ll sum = 0;
   scanf("%d", &n);
   for(int i=0; i<n; i++) scanf("%d", &a[i]), sum += a[i];
   ll d = sum % n, c = n - d;
   printf("%lld\n", c * d);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}