#include <bits/stdc++.h>
using namespace std;
int main() {
int n;
double h;
cin >> n >> h;
vector<double> v;
for (int i = 0; i < n; ++i) {
double x;
cin >> x;
v.push_back(x);
}
sort(v.begin(), v.end());
double ans = 0;
ans = max(ans, v[0]);
ans = max(ans, h - v[n - 1]);
for (int i = 0; i + 1 < n; ++i) {
int gap = v[i + 1] - v[i];
ans = max(ans, gap * 0.5);
}
cout << fixed << setprecision(10) << ans << "\n";
}