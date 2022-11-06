#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e4+5;

void solve() {
   int n, m;
   scanf("%d %d", &n, &m);
   if(n == 1 and m == 1) puts("0");
   else if(n == 1 or m == 1) puts("1");
   else puts("2");
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}