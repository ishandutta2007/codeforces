#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 5e5+7;

char s[sz];

void solve() {
   int n;
   scanf("%d %s", &n, s);
   map <pair<int,int>, int> mp;
   for(int i=0, x=0, y=0; s[i]; i++) {
      if(s[i] == 'D') x++;
      else y++;
      int g = __gcd(x, y);
      int &ans = mp[make_pair(x / g, y / g)];
      printf("%d ", ++ans);
   }
   puts("");
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}