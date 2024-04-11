#include <bits/stdc++.h>
using namespace std;
int main() {
int n, x;
cin >> n >> x;
int ans = 0;
for(int i = 1; i <= n && i * i <= x; ++i) {
if (x % i == 0) {
if (i * i == x) {
++ans;
} else if (x / i <= n) {
ans += 2;
}
}
}
cout << ans << "\n";
}