#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e5+5;

int a[sz];

void solve() {
   int n, m;
   scanf("%d %d", &n, &m);
   for(int i=0; i<n; i++) scanf("%d", &a[i]), m -= a[i];
   printf("%d\n", max(0, -m));
}

int main() {
   int t; cin >> t;
   while(t--) solve();
}