#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 5e5+7;

void solve() {
   int n, a, b;
   scanf("%d %d %d", &n, &a, &b);
   if(n == a and n == b) puts("Yes");
   else if(a + b + 1 < n) puts("Yes");
   else puts("No");
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}