#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e5+7;

int a[sz];

void solve() {
   ll n;
   scanf("%lld", &n);
   printf("%lld %lld\n", -(n-1), n);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}