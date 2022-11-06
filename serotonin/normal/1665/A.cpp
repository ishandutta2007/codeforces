#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e6+7;

void solve() {
   int n;
   scanf("%d", &n);
   if(n == 5) {
      puts("1 2 1 1");
   }
   else if(n & 1) {
      n -= 3;
      printf("2 %d 2 1\n", n - 2);
   }
   else {
      n -= 2;
      printf("1 %d 1 1\n", n - 1);
   }
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}