#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e6+7;

int a[sz];

void solve() {
   int n;
   scanf("%d", &n);
   for(int i=0; i<n; i++) scanf("%d", &a[i]);

   int zer = 0;
   vector <int> pos, neg;
   for(int i=0; i<n; i++) {
      if(a[i] > 0) pos.push_back(a[i]);
      else if(a[i] < 0) neg.push_back(a[i]);
      else zer++;
   }

   if(pos.size() > 2 or neg.size() > 2) {
      puts("NO");
      return;
   }

   vector <int> ara;
   for(int x : pos) ara.push_back(x);
   for(int x : neg) ara.push_back(x);
   zer = min(zer, 2);
   while(zer--) ara.push_back(0);

   set <int> st;
   for(int x : ara) st.insert(x);
   int z = ara.size();
   for(int i=0; i<z; i++) {
      for(int j=i+1; j<z; j++) {
         for(int k=j+1; k<z; k++) {
            if(!st.count(ara[i] + ara[j] + ara[k])) {
               puts("NO");
               return;
            }
         }
      }
   }
   puts("YES");
}

int main() {
   int t; cin >> t;
   while(t--) solve();
}