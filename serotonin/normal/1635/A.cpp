#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+7;

int a[sz];

void solve() {
   int n, ans = 0;
   scanf("%d", &n);
   for(int i=0; i<n; i++) scanf("%d", &a[i]), ans |= a[i];
   printf("%d\n", ans);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}