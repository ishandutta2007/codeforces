#include <bits/stdc++.h>
using namespace std;
int main() {
vector<int> a, b;
int n, m;
cin >> n;
for(int i = 0; i < n; ++i) {
int x;
cin >> x;
a.push_back(x);
}
cin >> m;
for(int i = 0; i < m; ++i) {
int x;
cin >> x;
b.push_back(x);
}
sort(a.begin(), a.end());
sort(b.begin(), b.end());
int j = 0;
int ans = 0;
for(int i = 0; i < a.size(); ++i) {
while (j < b.size() && b[j] + 1 < a[i]) ++j;
if (j < b.size() && b[j] >= a[i] - 1 && b[j] <= a[i] + 1) {
++j;
++ans;
}
}
cout << ans << "\n";
}