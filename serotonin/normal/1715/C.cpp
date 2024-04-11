#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1e5+5;

ll ans;
int n, a[sz];

ll gnc(int i) {
   if(i > 1 and a[i] == a[i-1]) return n - i + 1;
   ll lhs = i, rhs = n - i + 1;
   return lhs * rhs;
}

ll fnc(int i) {
   ll res = gnc(i);
   if(i < n) res += gnc(i + 1);
   return res;
}

int main() {
   int q;
   cin >> n >> q;
   ans = n * (n + 1LL) / 2;
   for(int i=1; i<=n; i++) {
      int x;
      scanf("%d", &x);
      ans -= fnc(i);
      a[i] = x;
      ans += fnc(i);
   }
   while(q--) {
      int i, x;
      scanf("%d %d", &i, &x);
      ans -= fnc(i);
      a[i] = x;
      ans += fnc(i);
      printf("%lld\n", ans);
   }
}