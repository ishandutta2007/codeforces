#include <bits/stdc++.h>
using namespace std;
int main() {
int n, m;
cin >> n >> m;
for (int i = 0; i < n; ++i) {
for (int j = 0; j < m; ++j) {
string s;
cin >> s;
if (s[0] != 'W' && s[0] != 'B' && s[0] != 'G') {
cout << "#Color\n";
return 0;
}
}
}
cout << "#Black&White\n";
}