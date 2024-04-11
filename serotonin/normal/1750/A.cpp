#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 4e5+5;

int a[sz];

void solve() {
   int n;
   scanf("%d", &n);
   for(int i=0; i<n; i++) scanf("%d", &a[i]);
   if(a[0] == 1) puts("YES");
   else puts("NO");
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}