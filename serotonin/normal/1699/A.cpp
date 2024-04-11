#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 5e5+7;

void solve() {
   int n;
   scanf("%d", &n);
   if(n & 1) puts("-1");
   else printf("0 0 %d\n", n / 2);
}

int main() {
   int t; cin >> t;
   while(t--) solve();
}