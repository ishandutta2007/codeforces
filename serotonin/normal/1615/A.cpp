#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+7;

int a[sz];

void solve() {
   int n;
   scanf("%d", &n);
   ll sum = 0;
   for(int i=1; i<=n; i++) scanf("%d", &a[i]), sum += a[i];
   if(sum % n) puts("1");
   else puts("0");
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}