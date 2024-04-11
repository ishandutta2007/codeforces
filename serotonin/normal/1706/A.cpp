#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 7005;

char s[sz];
int a[sz];

void solve() {
   int n, m;
   scanf("%d %d", &n, &m);
   for(int i=0; i<m; i++) s[i] = 'B';
   for(int i=0; i<n; i++) {
      scanf("%d", &a[i]);
      int x = a[i] - 1, y = m - a[i];
      if(x > y) swap(x, y);
      if(s[x] == 'A') s[y] = 'A';
      else s[x] = 'A';
   }
   s[m] = 0; puts(s);
}

int main() {
   int t; cin >> t;
   while(t--) solve();
}