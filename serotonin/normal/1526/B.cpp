#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1e5;

bool ya[sz];

int main() {
   int z = 11;
   vector <int> ones;
   while(z < sz) {
      ones.push_back(z);
      z = z * 10 + 1;
   }
   set <int> can;
   can.insert(0);
   while(!can.empty()) {
      int u = *can.begin(); can.erase(can.begin());
      ya[u] = 1;
      for(int &x : ones) {
         int g = u + x;
         if(g > sz) break;
         can.insert(g);
      }
   }

   int t;
   cin >> t;
   while(t--) {
      int n;
      scanf("%d", &n);
      if(n >= sz or ya[n]) puts("YES");
      else puts("NO");
   }
}