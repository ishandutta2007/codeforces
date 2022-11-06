#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e6+7;

char s[sz];
int a[sz], b[sz];

void solve() {
   int n;
   scanf("%d", &n);
   for(int i=1; i<=n; i++) scanf("%d", &a[i]);

   printf("%d\n", n * 3);
   for(int i=1; i<=n; i+=2) {
      printf("1 %d %d\n", i, i+1);
      printf("2 %d %d\n", i, i+1);
      printf("2 %d %d\n", i, i+1);
      printf("1 %d %d\n", i, i+1);
      printf("2 %d %d\n", i, i+1);
      printf("2 %d %d\n", i, i+1);
   }
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}