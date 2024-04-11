#include <bits/stdc++.h>
using namespace std;
int main() {
int a, b;
cin >> a >> b;
int ans = 0;
while (a < b) {
++ans;
a *= 2;
}
int mod = 1 << ans;
ans += __builtin_popcount((a - b) % mod) + (a - b) / mod;
cout << ans << "\n";
}