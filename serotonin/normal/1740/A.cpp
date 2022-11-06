#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 6e5+5;

bool vis[sz];

void solve() {
   int n;
   scanf("%d", &n);
   for(int j=2; ; j++) {
      if(vis[j]) continue;
      if(!vis[n + j]) continue;
      printf("%d\n", j);
      return;
   }
}

int main() {
   for(int i=2; i<sz; i++) {
      if(vis[i]) continue;
      for(int j=i<<1; j<sz; j+=i) vis[j] = 1;
   }
   int t;
   cin >> t;
   while(t--) solve();
}