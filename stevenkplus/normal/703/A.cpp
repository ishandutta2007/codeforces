#include <bits/stdc++.h>
using namespace std;
int main() {
int n;
cin >> n;
int ans = 0;
for (int i = 0; i < n; ++i) {
int a, b;
cin >> a >> b;
if (a > b) ++ans;
else if (a < b) --ans;
}
if (ans > 0)
cout << "Mishka\n";
else if (ans < 0) cout << "Chris\n";
else cout << "Friendship is magic!^^\n";
}