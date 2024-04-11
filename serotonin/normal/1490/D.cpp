#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+5;

int a[sz], d[sz];

void fnc(int l, int r, int lvl) {
   if(l > r) return;
   int mx = 0;
   for(int i=l; i<=r; i++) mx = max(mx, a[i]);
   int who = 0;
   for(int i=l; i<=r; i++) if(mx == a[i]) who = i;
   d[who] = lvl;
   fnc(l, who - 1, lvl + 1);
   fnc(who + 1, r, lvl + 1);
}

void solve() {
   int n;
   scanf("%d", &n);
   for(int i=0; i<n; i++) scanf("%d", &a[i]);
   fnc(0, n-1, 0);
   for(int i=0; i<n; i++) printf("%d ", d[i]);
   puts("");
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}