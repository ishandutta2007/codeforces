#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
int n, m;
cin >> n >> m;
ll ans = 0;
vector<int> v(n), w(m);
for (int i = 0; i < n; ++i) {
cin >> v[i];
ans += 1LL * v[i] * m;
}
sort(v.begin(), v.end());
for (int j = 0; j < m; ++j) {
cin >> w[j];
}
sort(w.begin(), w.end());
if (v[n - 1] > w[0]){
cout << "-1\n";
return 0;
}
for(int i = 0; i < m; ++i) {
ans += w[i] - v[n - 1];
}
if (v[n - 1] != w[0]) {
if (n == 1) {
cout << "-1\n";
return 0;
}
ans += v[n - 1] - v[n - 2];
}
cout << ans << "\n";
}