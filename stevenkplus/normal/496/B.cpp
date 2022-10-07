#include <bits/stdc++.h>
using namespace std;
int main() {
int n;
cin >> n;
string s;
cin >> s;
string ans = s;
for (int i = 0; i < n; ++i) {
string c = s.substr(i) + s.substr(0, i);
int off = 10 - (c[0] - '0');
for (int j = 0; j < n; ++j) {
c[j] = '0' + (c[j] - '0' + off) % 10;
}
ans = min(ans, c);
}
cout << ans << "\n";
}