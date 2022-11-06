#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+5;

void solve() {
   int l, r;
   scanf("%d %d", &l, &r);
   if(l * 2 > r) puts("-1 -1");
   else printf("%d %d\n", l, l * 2);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}