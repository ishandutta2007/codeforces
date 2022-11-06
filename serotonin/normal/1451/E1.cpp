#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+5;

int getxor(int i, int j) {
   cout << "XOR " << i << " " << j << endl;
   int v;
   cin >> v;
   return v;
}

int getor(int i, int j) {
   cout << "OR " << i << " " << j << endl;
   int v;
   cin >> v;
   return v;
}

int getand(int i, int j) {
   cout << "AND " << i << " " << j << endl;
   int v;
   cin >> v;
   return v;
}

bool is(int x, int i) {
   if(x & (1 << i)) return 1;
   return 0;
}

int main() {
   int r, n = -1;
   cin >> r;
   while(r) r >>= 1, n++;

   int anb = getand(1, 2);
   int axb = getxor(1, 2);
   int cna = getand(1, 3);
   int cnb = getand(2, 3);
   int coa = getor(1, 3);
   int a, b, c = 0;
   a = b = anb;
   a |= cna;
   b |= cnb;

   int zcab = ~(cna | cnb);
   zcab &= axb;
   for(int i=0; i<n; i++) {
      if(zcab & (1 << i)) {
         if(coa & (1 << i)) a |= 1 << i;
         else b |= 1 << i;
      }
   }

   for(int i=0; i<n; i++) {
      if(is(a, i)) {
         if(is(cna, i)) c |= 1 << i;
      }
      else {
         if(is(coa, i)) c |= 1 << i;
      }
   }

   vector <int> ans;
   ans.push_back(a);
   ans.push_back(b);
   ans.push_back(c);

   for(int i=4; i<=(1<<n); i++) {
      int x = getxor(1, i);
      ans.push_back(x ^ a);
   }

   cout << "!";
   for(int x : ans) cout << " " << x;
   cout << endl;
}