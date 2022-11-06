#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 6e5+5;

int a[sz];

void solve() {
   int n;
   scanf("%d", &n);
   if(~n & 1) {
      for(int i=1; i<n-1; i+=2) printf("%d %d ", i + 1, i);
      printf("%d %d\n", n - 1, n);
   }
   else {
      printf("1 2 3 ");
      for(int i=4; i<n-1; i+=2) printf("%d %d ", i + 1, i);
      printf("%d %d\n", n - 1, n);
   }
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}