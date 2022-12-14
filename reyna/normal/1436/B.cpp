#include <bits/stdc++.h>

#define mp make_pair
#define x first
#define y second
#define pb push_back
#define ALL(x) (x).begin(), (x).end()
using namespace std;
typedef long long LL;
const int N = (int) 0, mod = (int) 0;


int is_prime(int x) {
   if (x == 1) return 0;
   for (int i = 2; i * i <= x; ++i) 
      if (x % i == 0)
         return 0;
   return 1;
}
int main() {
   ios_base::sync_with_stdio(0);
   int tc;
   cin >> tc;
   while (tc--) {
      int n;
      cin >> n;
      for (int cur = n + 1; cur; ++cur) {
         if (is_prime(cur) && !is_prime(cur - (n-1))) {
            for (int i = 0; i < n; ++i) {
               for (int j = 0; j < n; ++j) {
                  cout << (i == j ? cur - (n-1) : 1) << ' ';
               }
               cout << '\n';
            }
            break;
         }
      }
   }
}