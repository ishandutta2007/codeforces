#include <bits/stdc++.h>

#define mp make_pair
#define x first
#define y second
#define pb push_back
#define ALL(x) (x).begin(), (x).end()
using namespace std;
typedef long long LL;
const int N = (int) 0, mod = (int) 0;


int main() {
   ios_base::sync_with_stdio(0);
   int tc;
   cin >> tc;
   while (tc--) {
      int n, m;
      cin >> n >> m;
      for (int j = 0; j < n; ++j) {
         int x;
         cin >> x;
         m -= x;
      }
      cout << (m == 0 ? "YES\n" : "NO\n");
   }
}