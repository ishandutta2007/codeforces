#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e6+7;

void solve() {
   int n;
   scanf("%d", &n);
   for(int i=0; i<n; i++) {
      for(int j=0; j<=i; j++) printf("(");
      for(int j=0; j<=i; j++) printf(")");
      for(int j=i+1; j<n; j++) printf("()");
      puts("");
   }
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}