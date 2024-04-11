#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2005;

char s[sz];
int dp[sz][sz];
bool vis[sz][sz];

int fnc(int l, int r);

int res(int l, int r, char a) {
   int one = 1;
   {
      char b = s[l++];
      if(fnc(l, r) < 0) one = -1;
      else if(!fnc(l, r) and a > b) one = -1;
      else if(!fnc(l, r) and a == b) one = min(one, 0);
      l--;
   }
   {
      char b = s[r--];
      if(fnc(l, r) < 0) one = -1;
      else if(!fnc(l, r) and a > b) one = -1;
      else if(!fnc(l, r) and a == b) one = min(one, 0);
      r++;
   }
   return one;
}

int fnc(int l, int r) {
   if(l > r) return 0;
   int &w = dp[l][r];
   if(vis[l][r]) return w;
   vis[l][r] = 1;

   w = -1;
   {
      char a = s[l++];
      w = max(w, res(l, r, a));
      l--;
   }
   {
      char a = s[r--];
      w = max(w, res(l, r, a));
      r++;
   }
   return w;
}

void solve() {
   scanf("%s", s + 1);
   int n = strlen(s + 1);
   for(int i=0; i<=n; i++) memset(vis[i], 0, sizeof(vis[i]));
   int res = fnc(1, n);
   if(res > 0) puts("Alice");
   else if(res < 0) puts("Bob");
   else puts("Draw");
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}