#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 405;

char s[sz][sz];

void solve() {
   int n;
   scanf("%d", &n);
   for(int i=0; i<n; i++) scanf("%s", s[i]);

   vector <pair<int,int>> v;
   for(int i=0; i<n; i++) {
      for(int j=0; j<n; j++) {
         if(s[i][j] == '*') v.emplace_back(i, j);
      }
   }

   int x1 = v[0].first, x2 = v[1].first;
   int y1 = v[0].second, y2 = v[1].second;
   if(x1 == x2) x2 = x1 ? 0 : n-1;
   if(y1 == y2) y2 = y1 ? 0 : n-1;

   s[x1][y1] = '*';
   s[x1][y2] = '*';
   s[x2][y2] = '*';
   s[x2][y1] = '*';
   for(int i=0; i<n; i++) puts(s[i]);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}