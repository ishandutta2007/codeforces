#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+5;

int a[sz];

void solve() {
   int n;
   scanf("%d", &n);
   for(int i=0; i<n; i++) scanf("%d", &a[i]);
   sort(a, a + n);
   printf("%d\n", a[n-1] + a[n-2] - a[0] - a[1]);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}