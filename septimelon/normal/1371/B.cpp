#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
    ll n, r;
    cin >> n >> r;
    ll t = min(n - 1, r);
    ll ans = t * (t + 1) / 2;
    if (n <= r) {
        ++ans;
    }
    cout << ans << "\n";
}

int main() {
   int t;
   cin >> t;
   for (int i = 0; i < t; ++i) {
       solve();
   }
   
   return 0;
}