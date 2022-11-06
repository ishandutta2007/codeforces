#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e5+5;

int a[sz];

void solve() {
   int n;
   scanf("%d", &n);
   int z = 0, one = 0;
   for(int i=0; i<n; i++) scanf("%d", &a[i]), z += !a[i], one += a[i] == 1;
   printf("%lld\n", one * (1LL << z));
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}