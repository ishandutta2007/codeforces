#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 305;

typedef pair <int, int> pii;
#define x first
#define y second

int s[sz][sz], r[sz], c[sz];

int main()
{
   int t;
   cin >> t;
   while(t--) {
      int n, k;
      cin >> n >> k;
      memset(s, 0, sizeof(s));
      memset(r, 0, sizeof(r));
      memset(c, 0, sizeof(c));

      vector <pii> b;
      for(int i=0; i<n; i++) {
         b.emplace_back(i, 0);
      }

      for(auto p : b) {
         int x = p.x, y = p.y;
         while(k && y < n) {
            s[x][y] = 1;
            r[x]++, c[y]++;
            x++, y++, k--;
            if(x == n) x = 0;
         }
      }

      int rmx = 0, rmn = n;
      int cmx = 0, cmn = n;
      for(int i=0; i<n; i++) cmn = min(cmn, c[i]), cmx = max(cmx, c[i]);
      for(int i=0; i<n; i++) rmn = min(rmn, r[i]), rmx = max(rmx, r[i]);

      int dr = rmx - rmn, dc = cmx - cmn;
      printf("%d\n", dr * dr + dc * dc);
      for(int i=0; i<n; i++) {
         for(int j=0; j<n; j++) printf("%d", s[i][j]);
         puts("");
      }
   }
}