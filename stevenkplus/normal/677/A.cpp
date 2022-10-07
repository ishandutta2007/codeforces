#include <bits/stdc++.h>
using namespace std;
int main() {
int n, h;
cin >> n >> h;
int ans = 0;
for(int i = 0; i < n; ++i) {
int x;
cin >> x;
if (x <= h) ++ans;
else ans += 2;
}
cout << ans << "\n";
}