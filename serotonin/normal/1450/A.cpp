#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+5;

char s[sz];

void solve() {
   int n;
   scanf("%d %s", &n, s);
   sort(s, s+n);
   printf("%s\n", s);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}