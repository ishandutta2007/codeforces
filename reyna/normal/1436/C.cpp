#include <bits/stdc++.h>

#define mp make_pair
#define x first
#define y second
#define pb push_back
#define ALL(x) (x).begin(), (x).end()
using namespace std;
typedef long long LL;
const int N = (int) 1e6 + 6, mod = (int) 1e9 + 7;

int mark[N];
int main() {
   ios_base::sync_with_stdio(0);
   int n, x, pos;
   cin >> n >> x >> pos;
   --x;
   int left = 0;
   int right = n;
   int ln = 0, rn = 0;
   while (left < right) {
      int middle = (left + right) / 2;
      mark[middle] = 1;
      if (middle + 1 <= pos + 1 && pos + 1 <= right) {
         left = middle + 1;
         ln += (middle != pos);
      } else {
         right = middle;
         rn += (middle != pos);
      }
   }
   int cnt = 0;
   for (int i = 0; i < n; ++i) cnt += !mark[i];
   int res = 1;
   for (int i = 0; i < cnt; ++i) res = (long long) res * (i+1) % mod;
   for (int i = 0; i < ln; ++i) res = (long long) res * (x - i) % mod;
   for (int i = 0; i < rn; ++i) res = (long long) res * (n - x - 1 - i) % mod;
   cout << res << endl;

}