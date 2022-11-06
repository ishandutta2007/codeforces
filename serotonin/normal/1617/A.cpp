#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+7;

void solve() {
   string s, t;
   cin >> s >> t;
   if(t == "abc") {
      bool ya[30] = {};
      for(char x : s) ya[x - 'a'] = 1;
      if(ya[0] and ya[1] and ya[2]) {
         for(char &x : s) {
            if(x == 'b') x = 'c';
            else if(x == 'c') x = 'b';
         }
         sort(s.begin(), s.end());
         for(char &x : s) {
            if(x == 'b') x = 'c';
            else if(x == 'c') x = 'b';
         }
         cout << s << '\n';
      }
      else {
         sort(s.begin(), s.end());
         cout << s << '\n';
      }
   }
   else {
      sort(s.begin(), s.end());
      cout << s << '\n';
   }
}

int main() {
   ios_base::sync_with_stdio(0); cin.tie(0);
   int t;
   cin >> t;
   while(t--) solve();
}