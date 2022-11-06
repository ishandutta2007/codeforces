#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e6+7;

char s[sz];

void solve() {
   scanf("%s", s);
   int n = strlen(s), ans = 0;
   for(int i=0; i<n; ans++) {
      set <char> st;
      for(; i<n; i++) {
         st.insert(s[i]);
         if(st.size() > 3) break;
      }
   }
   printf("%d\n", ans);
}

int main() {
   int t; cin >> t;
   while(t--) solve();
}