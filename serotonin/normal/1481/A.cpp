#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e6+7;

char s[sz];

void solve() {
   int x, y;
   scanf("%d %d %s", &x, &y, s);
   map <char,int> mp;
   for(int i=0; s[i]; i++) mp[s[i]]++;
   bool yes = 1;
   if(x > 0) yes &= mp['R'] >= x;
   else if(x < 0) yes &= mp['L'] >= -x;
   if(y > 0) yes &= mp['U'] >= y;
   else if(y < 0) yes &= mp['D'] >= -y;
   if(yes) puts("YES");
   else puts("NO");
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}