#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+5;

void solve() {
   int n;
   scanf("%d", &n);
   printf("9");
   n--;
   for(int i=0, j=8; i<n; i++, j++) {
      if(j == 10) j = 0;
      printf("%d", j);
   }
   puts("");
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}