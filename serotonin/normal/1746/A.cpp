#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+5;

int a[sz];

void solve() {
   int n, k;
   scanf("%d %d", &n, &k);
   for(int i=0; i<n; i++) scanf("%d", &a[i]);
   sort(a, a + n);
   puts(a[n - 1] ? "YES" : "NO");
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}