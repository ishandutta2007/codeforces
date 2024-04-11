#include <bits/stdc++.h>
using namespace std;
int main() {
cout << fixed << setprecision(10);
int n, k;
cin >> n >> k;
double ans = 0;
for (int i = 0; i < n; ++i) {
double x;
cin >> x;
ans += x * (min(k, i + 1) + min(k, n - i) - k) / (n - k + 1);
}
cout << ans << "\n";
}