#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1<<19, M = 998244353;

char s[sz];
string str[sz];

int main() {
   int m;
   cin >> m;
   scanf("%s", s + 1);
   int n = (1 << m) - 1, ans = 1;
   for(int i=n; i; i--) {
      str[i] = s[i];
      int l = i << 1, r = l | 1;
      if(l > n) continue;
      if(str[l] > str[r]) swap(str[l], str[r]);
      str[i] = s[i] + str[l] + str[r];
      ans = (ans << (str[l] != str[r])) % M;
   }
   cout << ans;
}