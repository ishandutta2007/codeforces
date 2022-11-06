#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+7;

void solve() {
   int l1, r1, l2, r2;
   scanf("%d %d %d %d", &l1, &r1, &l2, &r2);
   int ans = 200;
   for(int i=200; i; i--) {
      if(l1 <= i and i <= r1 and l2 <= i and i <= r2) ans = i;
   }
   printf("%d\n", min(l1 + l2, ans));
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}