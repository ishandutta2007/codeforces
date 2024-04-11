#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 4e5+5;

int ca[sz], cb[sz];

ll fnc(ll n) {
   return n * (n - 1) / 2;
}

void solve() {
   int a, b, k;
   scanf("%d %d %d", &a, &b, &k);
   for(int i=0, x; i<k; i++) scanf("%d", &x), ca[x]++;
   for(int i=0, x; i<k; i++) scanf("%d", &x), cb[x]++;
   ll ans = fnc(k);
   for(int i=1; i<=a; i++) ans -= fnc(ca[i]), ca[i] = 0;
   for(int i=1; i<=b; i++) ans -= fnc(cb[i]), cb[i] = 0;
   printf("%lld\n", ans);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}