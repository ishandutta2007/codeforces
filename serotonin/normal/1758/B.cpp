#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e6+7;

void solve() {
   int n;
   scanf("%d", &n);
   if(n & 1) {
      while(n--) printf("1 ");
      puts("");
   }
   else {
      printf("1 3 "); n -= 2;
      while(n--) printf("2 ");
      puts("");
   }
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}