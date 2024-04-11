#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e6+7;

void solve() {
   int k;
   scanf("%d", &k);
   int j = 100 - k;
   int g = __gcd(j, k);
   k /= g, j /= g;
   printf("%d\n", k + j);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}