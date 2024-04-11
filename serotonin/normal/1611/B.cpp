#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+5;

int a[sz];

void solve() {
   ll a, b;
   scanf("%lld %lld", &a, &b);
   if(a > b) swap(a, b);
   if(a * 3 <= b) printf("%d\n", a);
   else printf("%d\n", (a + b) / 4);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}