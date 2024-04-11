#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1e5+5;

int a[sz], b[sz];

void solve() {
   int n;
   scanf("%d", &n);
   for(int i=0; i<n; i++) scanf("%d", &a[i]);
   for(int i=0; i<n; i++) scanf("%d", &b[i]);
   for(int i=0; i<n; i++) if(a[i] > b[i]) swap(a[i], b[i]);
   ll ans = 0;
   for(int i=1; i<n; i++) ans += abs(a[i] - a[i-1]);
   for(int i=1; i<n; i++) ans += abs(b[i] - b[i-1]);
   printf("%lld\n", ans);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}