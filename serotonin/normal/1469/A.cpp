#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+5;

char s[sz];

void solve() {
   scanf("%s", s);
   int n = strlen(s);
   if(n & 1) puts("NO");
   else if(s[0] == ')' || s[n-1] == '(') puts("NO");
   else puts("YES");
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}