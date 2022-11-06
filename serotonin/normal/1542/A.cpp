#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e6+7;

int a[sz];

void solve() {
   int n, od = 0;
   scanf("%d", &n);
   for(int i=0; i<2*n; i++) scanf("%d", &a[i]), od += (a[i] & 1);
   if(od == n) puts("Yes");
   else puts("No");
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}