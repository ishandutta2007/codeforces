#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
ll h, n;
cin >> h >> n;
vector<ll> ar;
ll cur = 0;
ll mn = 0;
for (int i = 0; i < n; ++i) {
int x;
cin >> x;
cur += x;
ar.push_back(cur);
mn = min(mn, cur);
}
ll t = ar[n - 1];
ll ans = 0;
if (mn <= -h) {
// pass
} else if (t >= 0) {
cout << "-1\n";
return 0;
} else {
ans += (h + mn + -t - 1) / -t * n;
h +=  (h + mn + -t - 1) / -t * t;
}
if (h > 0)
for (int i = 0; i < n; ++i) {
++ans;
if (ar[i] <= -h) break;
}
cout << ans << "\n";
}