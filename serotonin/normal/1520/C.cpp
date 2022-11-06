#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 205;

int ans[sz][sz];

void solve() {
   int n;
   scanf("%d", &n);
   if(n == 2) {
      puts("-1");
      return;
   }

   vector <int> a;
   a.push_back(n - 1);
   for(int i=1; i<n; i++) {
      a.push_back(n - 1 - i);
      a.push_back(n - 1 + i);
   }
   int k = 1;
   for(int s : a) {
      for(int i=0, j=s; i<n; i++, j--) {
         if(j >= 0 and j < n) ans[i][j] = k++;
      }
   }

   for(int i=0; i<n; i++) {
      for(int j=0; j<n; j++) {
         printf("%d ", ans[i][j]);
      }
      puts("");
   }
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}