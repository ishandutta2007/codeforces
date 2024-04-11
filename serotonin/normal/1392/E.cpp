#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 25;

int n;
ll a[sz][sz], k;
vector <pair<int,int>> ans;

void go(int x, int y, int b) {
   ll v = k & (1LL << b);
   ans.emplace_back(x, y);
   if(x == n-1 && y == n-1) return;
   if(x + 1 < n && a[x+1][y] == v) go(x+1, y, b+1);
   else go(x, y+1, b+1);
}

int main() {
   for(int j=0; j<sz; j++) {
      if(j & 1) {
         for(int i=0, k=j-1; i<sz; i++, k++) {
            a[i][j] = 1LL << k;
         }
      }
   }

   cin >> n;
   for(int i=0; i<n; i++) {
      for(int j=0; j<n; j++) {
         cout << a[i][j] << " ";
      }
      cout << endl;
   }

   int q;
   cin >> q;
   while(q--) {
      cin >> k;
      go(0, 0, 0);
      for(auto p : ans) cout << p.first + 1 << " " << p.second + 1 << endl;
      ans.clear();
   }
}