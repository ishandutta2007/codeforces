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

int fnc(int sus, int cru) {
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

int fsus(int sus, int c) {
   bool one = ask(sus, sus + 1, c);
   bool two = ask(sus, sus + 2, c);
   if(one and two) {
      // sus + 1 and sus + 2
      return 6;
   }
   else if(one) {
      return 5;
   }
   else if(two) {
      return 3;
   }
   else return 7;
}

int fcru(int sus, int c) {
   bool one = ask(sus, sus + 1, c) ^ 1;
   bool two = ask(sus, sus + 2, c) ^ 1;
   if(one and two) {
      // sus + 1 and sus + 2
      return 6;
   }
   else if(one) {
      return 5;
   }
   else if(two) {
      return 3;
   }
   else return 7;
}

void solve() {
   int n, sus = 0, cru = 0;
   scanf("%d", &n);
   for(int i=1; i<n; i+=3) {
      int &x = wut[i] = ask(i, i+1, i+2);
      if(!x) sus = i;
      else cru = i;
   }
   ans[sus] = fnc(sus, cru);
   int xsus;
   for(int j=0; j<3; j++) if(ans[sus] & 1 << j) xsus = sus + j;
   ans[cru] = fcru(cru, xsus);
   int xcru;
   for(int j=0; j<3; j++) if(ans[cru] & 1 << j) xcru = cru + j;

   for(int i=1; i<n; i+=3) {
      if(i == sus or i == cru) continue;
      int x = wut[i];
      if(x) ans[i] = fcru(i, xsus);
      else ans[i] = fsus(i, xcru);
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