#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e4+7;

int a[sz];
bool vis[sz];

int ask(int x) {
   printf("? %d\n", x); fflush(stdout);
   int v;
   scanf("%d", &v);
   return v;
}

void solve() {
   int n;
   scanf("%d", &n);
   for(int i=1; i<=n; i++) a[i] = vis[i] = 0;
   for(int i=1; i<=n; i++) {
      if(a[i]) continue;
      vector <int> ara;
      while(1) {
         int x = ask(i);
         if(vis[x]) break;
         vis[x] = 1;
         ara.push_back(x);
      }
      ara.push_back(ara[0]);
      for(int i=1; i<ara.size(); i++) {
         int x = ara[i], y = ara[i-1];
         a[y] = x;
      }
   }
   printf("!");
   for(int i=1; i<=n; i++) printf(" %d", a[i]);
   puts("");
   fflush(stdout);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}