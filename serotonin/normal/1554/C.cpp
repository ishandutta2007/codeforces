#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 55;

void solve() {
   int n, m;
   scanf("%d %d", &n, &m);
   int b = (1 << 30) - 1;
   for(int i=29; i>=0; i--) {
      int x = b ^ (1 << i);
      if(x > m and (x ^ n) < (b ^ n)) b = x;
   }
   printf("%d\n", b ^ n);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}