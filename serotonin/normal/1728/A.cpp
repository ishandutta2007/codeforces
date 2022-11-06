#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 6e5+5;

int a[sz];

void solve() {
   int n;
   scanf("%d", &n);
   for(int i=1; i<=n; i++) scanf("%d", &a[i]);
   int ans = 1;
   for(int i=2; i<=n; i++) if(a[i] > a[ans]) ans = i;
   printf("%d\n", ans);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}