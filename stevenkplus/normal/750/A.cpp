#include <bits/stdc++.h>
using namespace std;
int main() {
int n, k;
cin >> n >> k;
k = (240 - k) / 5;
int ans = 0;
for(int i = 1; i <= n; ++i) {
if (i <= k) {
k -= i;
ans = i;
} else break;
}
cout << ans << "\n";
}