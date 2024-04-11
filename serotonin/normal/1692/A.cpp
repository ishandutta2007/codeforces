#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+7;

int a[sz];

void solve() {
   int n = 4;
   for(int i=1; i<=n; i++) scanf("%d", &a[i]);
   int cnt = 0;
   for(int i=2; i<=n; i++) cnt += a[i] > a[1];
   printf("%d\n", cnt);
}

int main() {
   int t; cin >> t;
   while(t--) solve();
}