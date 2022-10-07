#include <bits/stdc++.h>
using namespace std;
int main() {
int k, n, w;
cin >> k >> n >> w;
int cost = w * (w + 1) / 2 * k;
int ans = max(0, cost - n);
cout << ans << "\n";
}