#include <bits/stdc++.h>
using namespace std;
int main() {
int n;
cin >> n;
string s;
cin >> s;
int ans = 0;
for(int i = 0; i < n; ++i) {
if (s[i] == '0') ++ans;
else --ans;
}
cout << abs(ans) << "\n";
}