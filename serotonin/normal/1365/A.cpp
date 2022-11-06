#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+5;

int a[55][55];

int main()
{
   int t;
   cin >> t;
   while(t--) {
      int n, m;
      cin >> n >> m;
      for(int i=0; i<n; i++) {
         for(int j=0; j<m; j++) {
            scanf("%d", &a[i][j]);
         }
      }

      int x = 0;
      for(int i=0; i<n; i++) {
         bool no = 0;
         for(int j=0; j<m; j++) {
            if(a[i][j]) no = 1;
         }
         if(!no) x++;
      }

      int y = 0;
      for(int j=0; j<m; j++) {
         bool no = 0;
         for(int i=0; i<n; i++) {
            if(a[i][j]) no = 1;
         }
         if(!no) y++;
      }

      int z = min(x, y);

      if(z & 1) puts("Ashish");
      else puts("Vivek");
   }
}