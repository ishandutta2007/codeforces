#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e6+7;

char s[sz];

void solve() {
   scanf("%s", s);
   int n = strlen(s);
   printf("%s", s);
   reverse(s, s + n);
   printf("%s\n", s);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}