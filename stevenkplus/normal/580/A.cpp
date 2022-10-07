#include <bits/stdc++.h>
using namespace std;
int main() {
int n;
cin >> n;
int ans = 0;
int run = 0;
int prev = 0;
for(int i = 0; i < n; ++i) {
int x;
cin >> x;
if (x < prev) run = 0;
prev = x;
++run;
ans = max(ans, run);
}
cout << ans << "\n";
}