#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1e6+5;

char s[sz];

void solve() {
   int n;
   scanf("%d %s", &n, s);
   for(int i=0; i<n; i++) printf("%c", s[n-1]);
   puts("");
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}