#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+7;

char a[sz];

void solve() {
   int n;
   scanf("%d %s", &n, a);
   string s = a;
   set <char> one;
   for(int i=0; i<n; i++) one.insert(s[i]);
   for(int i=0; i<26; i++) if(!one.count('a' + i)) {
      printf("%c\n", 'a' + i);
      return;
   }

   set <string> two, three;
   for(int i=0; i<n-1; i++) {
      two.insert(s.substr(i, 2));
      if(i < n-2) three.insert(s.substr(i, 3));
   }

   for(int i=0; i<26; i++) {
      for(int j=0; j<26; j++) {
         string t;
         t += ('a' + i);
         t += ('a' + j);
         if(!two.count(t)) {
            cout << t << '\n';
            return;
         }
      }
   }

   for(int i=0; i<26; i++) {
      for(int j=0; j<26; j++) {
         for(int k=0; k<26; k++) {
            string t;
            t += ('a' + i);
            t += ('a' + j);
            t += ('a' + k);
            if(!three.count(t)) {
               cout << t << '\n';
               return;
            }
         }
      }
   }
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}