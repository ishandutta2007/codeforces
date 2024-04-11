#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+7;

bool a[sz];

void solve() {
   int n;
   cin >> n;
   bool yes = 0;
   for(int i=0; i<n; i++) {
      int x;
      scanf("%d", &x);
      if(a[x]) continue;
      yes = 1;
   }
   if(yes) puts("YES");
   else puts("NO");
}

int main() {
   for(int i=0; i<101; i++) a[i * i] = 1;
   int t;
   cin >> t;
   while(t--) solve();
}