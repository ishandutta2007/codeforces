#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1005;

int a[sz];
vector <int> ans[sz];

void solve() {
   int n;
   scanf("%d", &n);
   for(int i=1; i<=n; i++) scanf("%d", &a[i]);
   for(int i=1; i<=n; i++) {
      if(a[i] == 1) {
         ans[i] = ans[i - 1];
         ans[i].push_back(1);
      }
      else {
         ans[i] = ans[i - 1];
         while(!ans[i].empty() and ans[i].back() + 1 != a[i]) ans[i].pop_back();
         ans[i].back()++;
      }
      for(int j=0; j<ans[i].size(); j++) {
         if(j) printf(".");
         printf("%d", ans[i][j]);
      }
      puts("");
   }
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}