#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e5+6;

int a[sz];

void solve() {
   int n, m;
   scanf("%d %d", &n, &m);
   for(int i=0; i<m; i++) scanf("%d", &a[i]);
   sort(a, a + m);

   if(m == 1) {
      puts("2");
      return;
   }

   vector <int> ara;
   for(int i=1; i<m; i++) ara.push_back(a[i] - a[i-1] - 1);
   ara.push_back(n + a[0] - a[m-1] - 1);
   sort(ara.begin(), ara.end());
   reverse(ara.begin(), ara.end());

   int ans = 0;
   for(int i=0; i<ara.size(); i++) {
      int d = ara[i] - i * 4;
      if(d <= 0) break;
      ans += max(1, d - 1);
   }
   printf("%d\n", n - ans);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}