#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 4e6+7;

int a[sz];

void solve() {
   int n;
   scanf("%d", &n);
   for(int i=0; i<n; i++) scanf("%d", &a[i]);
   int g = a[0];
   for(int i=1; i<n; i++) g = __gcd(g, a[i] - a[i-1]);
   printf("%d\n", a[n-1] / g);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}