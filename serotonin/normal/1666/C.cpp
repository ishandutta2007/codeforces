#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+5;

int main() {
   int ax[3], ay[3];
   for(int i=0; i<3; i++) cin >> ax[i] >> ay[i];

   vector <int> y(ay, ay + 3);
   sort(y.begin(), y.end());
   vector <int> x(ax, ax + 3);
   sort(x.begin(), x.end());
   
   vector <tuple<int,int,int,int>> ans;
   if(x[0] ^ x[2]) {
      ans.emplace_back(x[0], y[1], x[2], y[1]);
   }

   for(int i=0; i<3; i++) {
      if(ay[i] ^ y[1]) {
         ans.emplace_back(ax[i], ay[i], ax[i], y[1]);
      }
   }

   printf("%d\n", ans.size());
   for(auto [a, b, c, d] : ans) printf("%d %d %d %d\n", a, b, c, d);
}