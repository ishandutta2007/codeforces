#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+7;

int a[sz];

void solve() {
   char s[10][10];
   for(int i=0; i<8; i++) scanf("%s", s[i]);
   for(int i=1; i<7; i++) {
      for(int j=1; j<7; j++) {
         if(s[i][j] == '#' and s[i+1][j+1] == '#' and s[i-1][j+1] == '#' and s[i+1][j-1] == '#' and s[i-1][j-1] == '#') {
            printf("%d %d\n", i + 1, j + 1);
            return;
         }
      }
   }
}

int main() {
   int t; cin >> t;
   while(t--) solve();
}