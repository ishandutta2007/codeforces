#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 5e5+7;

int a[sz];

void solve() {
   int n;
   scanf("%d", &n);
   set <int> st;
   for(int i=0; i<n; i++) scanf("%d", &a[i]);
   st.insert(a[0]);
   for(int i=1; i<n; i++) {
      int x = a[i], y = a[i-1];
      if(x == y) continue;
      st.insert(x);
      if(x > y) swap(x, y);
      if(*st.upper_bound(x) != y) {
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