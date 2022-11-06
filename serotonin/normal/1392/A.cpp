#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1e6+7;

int a[sz];

void solve() {
   int n;
   cin >> n;
   for(int i=0; i<n; i++) scanf("%d", &a[i]);
   sort(a, a+n);
   if(a[0] == a[n-1]) printf("%d\n", n);
   else puts("1");
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}