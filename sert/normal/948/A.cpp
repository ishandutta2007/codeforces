#include<bits/stdc++.h>
using namespace std;
int main() {
int n, m;
string s[1000];
cin >> n >> m;
for (int i = 0; i < n; i++) cin >> s[i];
for (int i = 0; i < n; i++) for (int j = 1; j < m; j++)
if (s[i][j] + s[i][j - 1] == 'S' + 'W') {cout << "NO"; return 0;}
for (int i = 1; i < n; i++) for (int j = 0; j < m; j++)
if (s[i][j] + s[i - 1][j] == 'S' + 'W') {cout << "NO"; return 0;}
cout << "YES\n";
for (int i = 0; i < n; i++) {
for (int j = 0; j < m; j++)
cout << (s[i][j] == '.' ? 'D' : s[i][j]);
cout << "\n";
}
return 0;
}