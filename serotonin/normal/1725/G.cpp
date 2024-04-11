#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1e5+5;

int a[sz];

int main() {
   // 1, 4 bad
   // every odd * 2 bad
   ll n;
   cin >> n;
   if(n == 1) cout << 3;
   else if(n == 2) cout << 5;
   else {
      n -= 3;
      ll x = n / 3 * 4 + 7 + n % 3;
      cout << x;
   }
   // 7, 8, 9
   // 11, 12, 13
}