#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 4e5+7;

char s[sz];

void solve() {
   scanf("%s", s);
   int n = strlen(s);
   int zer = -1, one = n+1;
   for(int i=1; i<n; i++) if(s[i] == s[i-1]) {
      if(s[i] == '0') zer = max(zer, i);
      else one = min(one, i);
   }
   puts(one > zer ? "yes" : "no");
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}