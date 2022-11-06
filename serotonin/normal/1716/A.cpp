#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1e5+7;

void solve() {
   int n;
   scanf("%d", &n);
   if(n == 1) puts("2");
   else printf("%d\n", 1 + (n - 1) / 3);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}