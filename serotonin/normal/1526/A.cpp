#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1e5+7;

int a[sz];

void solve() {
   int n;
   scanf("%d", &n);
   n <<= 1;
   for(int i=0; i<n; i++) scanf("%d", &a[i]);

   sort(a, a+n);
   for(int i=0; i<n/2; i++) printf("%d %d ", a[i], a[n/2+i]);
   puts("");
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}