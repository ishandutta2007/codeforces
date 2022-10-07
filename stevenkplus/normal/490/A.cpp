#include <bits/stdc++.h>
using namespace std;
int main() {
int n;
cin >> n;
vector<int> v[3];
for (int i = 1; i <= n; ++i) {
int x;
cin >> x;
v[x - 1].push_back(i);
}
int ans = min(min(v[0].size(), v[1].size()), v[2].size());
cout << ans << "\n";
for (int i = 0; i < ans; ++i) {
for(int j = 0; j < 3; ++j) {
cout << v[j][i] << " ";
}
cout << "\n";
}
}