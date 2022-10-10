#include <bits/stdc++.h>
using namespace std; int main() {string s;
cin >> s;
int x = 0, y = 0;
for (char c  : s)
    if (c == 'o')
    x++;
else
y++;
if (x == 0 || y % x == 0) cout << "YES\n";
else cout << "NO\n";
}