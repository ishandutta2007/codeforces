#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 25, mod = 1e9+7;

int invmod(int a, int m) {
   if(m == 1) return 0;
   int m0 = m, y = 0, x = 1;
   while(a > 1) {
      int q = a / m;
      int t = m;
      m = a % m, a = t;
      t = y;
      y = x - q * y;
      x = t;
   }
   if(x < 0) x += m0;
   return x;
}

int main() {
   int n;
   cin >> n;
   ll ans = 1;
   vector <int> ara;
   for(int i=1; i<n; i++) {
      if(__gcd(n, i) == 1) ans = ans * i % n, ara.push_back(i);
   }

   if(ans ^ 1) {
      for(int i=0; i<ara.size(); i++) {
         if(ans * invmod(ara[i], n) % n == 1) {
            ara.erase(ara.begin() + i, ara.begin() + i + 1);
            break;
         }
      }
   }
   ans = 1;
   printf("%d\n", ara.size());
   for(int x : ara) printf("%d ", x), ans = ans * x % n;
   assert(ans == 1);
}