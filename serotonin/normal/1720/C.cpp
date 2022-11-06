#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1005;

char s[sz][sz];

void solve() {
   int n, m;
   scanf("%d %d", &n, &m);
   for(int i=0; i<n; i++) scanf("%s", s[i]);

   int ans = 0;
   bool zer = 0, two = 0;
   for(int i=0; i<n; i++) {
      for(int j=0; j<m; j++) {
         if(s[i][j] == '1') ans++;
         else {
            zer = 1;
            for(int x=-1; x<=1; x++) {
               for(int y=-1; y<=1; y++) {
                  if(!x and !y) continue;
                  int ni = i + x;
                  int nj = j + y;
                  if(ni < 0 or nj < 0 or ni >= n or nj >= m) continue;
                  if(s[ni][nj] == '0') two = 1;
               }
            }
         }
      }
   }
   if(!zer) ans -= 2;
   else if(!two) ans--;
   printf("%d\n", ans);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}