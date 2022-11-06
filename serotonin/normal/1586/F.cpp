#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1005;

int ans, g[sz][sz];

void fnc(vector <int> a, vector <int> b) {
   for(int x : a) {
      for(int y : b) {
         g[x][y] = g[y][x] = ans;
      }
   }
}

int main() {
   int n, k;
   cin >> n >> k;
   vector <vector<int>> a;
   for(int i=1; i<=n; i++) a.push_back({i});

   while(a.size() > 1) {
      ans++;
      int z = a.size();
      vector <vector<int>> b;
      for(int l=0; l<z; l+=k) {
         int r = min(z, l+k);
         for(int i=l; i<r; i++) {
            for(int j=i+1; j<r; j++) {
               fnc(a[i], a[j]);
            }
         }
         vector <int> now;
         for(int i=l; i<r; i++) {
            for(int x : a[i]) now.push_back(x);
         }
         b.push_back(now);
      }
      a = b;
   }

   printf("%d\n", ans);
   for(int i=1; i<=n; i++) {
      for(int j=i+1; j<=n; j++) {
         printf("%d ", g[i][j]);
      }
   }
}