#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e5+5;

string s;

bool pal(string &x) {
   string y = x;
   reverse(y.begin(), y.end());
   return x == y;
}

void solve() {
   int n;
   cin >> n >> s;
   if(pal(s)) {
      cout << 0 << '\n';
      return;
   }

   int ans = n + 1;
   for(int i=0; i<26; i++) {
      string x; char ch = 'a' + i;
      for(char &c : s) if(c != ch) x += c;
      if(!pal(x)) continue;

      int l = 0;
      map <int,int> mp;
      for(char &c : s) {
         if(c != ch) l++;
         else mp[l]++;
      }

      string ss = s;
      reverse(ss.begin(), ss.end());
      int r = 0, now = 0;
      for(char &c : ss) {
         if(c != ch) r++;
         else if(mp[r]) mp[r]--;
         else now++;
      }
      ans = min(ans, now);
   }

   if(ans > n) ans = -1;
   cout << ans << '\n';
}

int main() {
   ios_base::sync_with_stdio(0); cin.tie(0);
   int t;
   cin >> t;
   while(t--) solve();
}