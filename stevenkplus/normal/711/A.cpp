#include <bits/stdc++.h>
using namespace std;
int main() {
int n;
cin >> n;
string s;
for (int i = 0; i < n; ++i) {
string line;
cin >> line;
s += line;
s += "\n";
}
int idx = s.find("OO");
if (idx != -1) {
s = s.substr(0, idx) + "++" + s.substr(idx + 2);
cout << "YES\n" << s;
} else {
cout << "NO\n";
}
}