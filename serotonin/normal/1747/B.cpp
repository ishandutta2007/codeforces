#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e6+5;

void solve() {
   int n;
   cin >> n;
   vector <pair<int,int>> ans;
   for(int i=1, j=n; i<=j; i++, j--) 
      ans.emplace_back(i * 3 - 2, j * 3);
   printf("%d\n", ans.size());
   for(auto [x, y] : ans) printf("%d %d\n", x, y);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}