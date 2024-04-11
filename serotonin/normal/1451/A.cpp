#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 5e5+5;

void solve() {
   int n;
   scanf("%d", &n);
   if(n == 1) puts("0");
   else if(n == 2) puts("1");
   else if(n == 3) puts("2");
   else if(n & 1) puts("3");
   else puts("2");
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}