#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+5;

void solve() {
   int a[3];
   for(int i=0; i<3; i++) scanf("%d", &a[i]);
   sort(a, a+3);

   if(a[1] == a[2]) {
      puts("YES");
      printf("%d %d 1\n", a[1], a[0]);
   }
   else puts("NO");
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}