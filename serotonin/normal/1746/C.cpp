#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+5;

int a[sz], w[sz];

void solve() {
   int n;
   scanf("%d", &n);
   for(int i=1; i<=n; i++) scanf("%d", &a[i]), w[a[i]] = i;
   
   for(int i=1; i<=n; i++) printf("%d ", min(w[i] + 1, n));
   puts("");
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}