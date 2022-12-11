#include<bits/stdc++.h>
using namespace std;
int main() {
int q;
string t, s;
cin >> q;
while (q --> 0) {
cin >> s >> t;
string ans = "NO";
for (char c1 : s) for (char c2 : t) if (c1 == c2) ans = "YES";
cout << ans << "\n";
}
}