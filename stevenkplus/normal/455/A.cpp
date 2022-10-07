#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 100100;
int ar[MAXN];
ll dp[MAXN];
int main() {
int n;
cin >> n;
for (int i = 0; i < n; ++i) {
int x;
cin >> x;
++ar[x];
}

for (int i = MAXN - 3; i >= 0; --i) {
dp[i] = max(dp[i + 1], dp[i + 2] + ll(i) * ar[i]);
}
cout << dp[0] << "\n";
}