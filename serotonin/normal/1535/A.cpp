#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e5+7;

void solve() {
   int a[4];
   for(int i=0; i<4; i++) scanf("%d", &a[i]);
   if(max(a[0], a[1]) < min(a[2], a[3])) puts("NO");
   else if(min(a[0], a[1]) > max(a[2], a[3])) puts("NO");
   else puts("YES");
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}