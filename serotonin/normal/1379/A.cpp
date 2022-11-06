#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+5;

char s[sz];

int fnc(const string &s) {
   int cnt = 0;
   for(int i=0; i<s.size() - 6; i++) {
      if(s.substr(i, 7) == "abacaba") cnt++;
   }
   return cnt;
}

void solve() {
   int n;
   scanf("%d %s", &n, s);
   int cnt = fnc(s);
   if(cnt > 1) {
      puts("NO");
      return;
   }
   if(cnt == 1) {
      puts("YES");
      for(int i=0; i<n; i++) if(s[i] == '?') s[i] = 'z';
      puts(s);
      return;
   }

   string a = "abacaba";
   for(int i=0; i<n-6; i++) {\
      bool no = 0;
      for(int j=0; j<7; j++) {
         if(s[j+i] ^ a[j] && s[j+i] != '?') no = 1;
      }
      if(!no) {
         string now;
         for(int j=0; j<n; j++) now += s[j];
         for(int j=0; j<7; j++) now[j+i] = a[j];
         if(fnc(now) > 1) continue;
         puts("YES");
         for(int j=0; j<7; j++) s[j+i] = a[j];
         for(int i=0; i<n; i++) if(s[i] == '?') s[i] = 'z';
         puts(s);
         return;
      }
   }
   puts("NO");
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}