#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1e4+7;

int wut[sz], ans[sz];

bool ask(int x, int y, int z) {
   printf("? %d %d %d\n", x, y, z);
   fflush(stdout);
   scanf("%d", &x);
   return x;
}

int fsus(int sus, int cru) {
   bool one = ask(sus, sus + 1, cru) | ask(sus, sus + 1, cru + 1);
   bool two = ask(sus + 2, sus + 1, cru) | ask(sus + 2, sus + 1, cru + 1);

   if(!one and !two) {
      // all impostors
      return 7;      
   }
   else if(!one) {
      // sus and sus + 1
      return 3;
   }
   else if(!two) {
      // sus + 1 and sus + 2
      return 6;
   }
   else {
      // sus and sus + 2
      return 5;
   }
}

int fcru(int cru, int sus) {
   bool one = ask(sus, sus + 1, cru) & ask(sus, sus + 1, cru + 1);
   bool two = ask(sus + 2, sus + 1, cru) & ask(sus + 2, sus + 1, cru + 1);

   one ^= 1, two ^= 1;

   if(!one and !two) {
      // all impostors
      return 7;      
   }
   else if(!one) {
      // sus and sus + 1
      return 3;
   }
   else if(!two) {
      // sus + 1 and sus + 2
      return 6;
   }
   else {
      // sus and sus + 2
      return 5;
   }
}

void solve() {
   int n, sus = 0, cru = 0;
   scanf("%d", &n);
   for(int i=1; i<n; i+=3) {
      int &x = wut[i] = ask(i, i+1, i+2);
      if(!x) sus = i;
      else cru = i;
   }
   for(int i=1; i<n; i+=3) {
      int x = wut[i];
      if(x) ans[i] = fcru(sus, i);
      else ans[i] = fsus(i, cru);
   }
   vector <int> res;
   for(int i=1; i<n; i+=3) {
      if(!wut[i]) {
         for(int j=0; j<3; j++) if(ans[i] & 1 << j) {
            res.push_back(i + j);
         }
      }
      else {
         for(int j=0; j<3; j++) if(~ans[i] & 1 << j) {
            res.push_back(i + j);
         }
      }
   }
   printf("! %d", res.size());
   for(int i : res) printf(" %d", i);
   cout << endl;
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}