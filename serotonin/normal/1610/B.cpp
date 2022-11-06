#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+5;

int a[sz];

bool fnc(vector <int> a) {
   vector <int> b = a;
   reverse(b.begin(), b.end());
   return a == b;
}

void solve() {
   int n;
   scanf("%d", &n);
   for(int i=1; i<=n; i++) scanf("%d", &a[i]);
   for(int i=1, j=n; i<j; i++, j--) {
      if(a[i] != a[j]) {
         vector <int> ara;
         for(int k=1; k<=n; k++) if(a[k] ^ a[i]) ara.push_back(a[k]);
         if(fnc(ara)) {
            puts("YES");
            return;
         }
         ara.clear();
         for(int k=1; k<=n; k++) if(a[k] ^ a[j]) ara.push_back(a[k]);
         if(fnc(ara)) {
            puts("YES");
            return;
         }
         puts("NO");
         return;
      }
   }
   puts("YES");
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}