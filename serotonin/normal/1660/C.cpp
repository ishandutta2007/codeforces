#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e5+7, inf = 1e8;

char s[sz];
int dp[sz][27];

int fnc(int i, int p) {
   if(!i) return p ? inf : 0;
   int &w = dp[i][p];
   if(w >= 0) return w;
   w = inf;
   int x = s[i] - 'a' + 1;
   w = min(w, 1 + fnc(i - 1, p));
   if(!p) w = min(w, fnc(i - 1, x));
   else if(x == p) w = min(w, fnc(i - 1, 0));
   return w;
}

void solve() {
   scanf("%s", s + 1);
   int n = strlen(s + 1);
   for(int i=0; i<=n; i++) memset(dp[i], -1, sizeof(dp[i]));
   printf("%d\n", fnc(n, 0));
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}