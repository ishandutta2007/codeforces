#include <bits/stdc++.h>
using namespace std;

string a, b;

string func(string s) {
	int n = s.length();
	if (n % 2) return s;
	string x = func(s.substr(0, n / 2));
	string y = func(s.substr(n / 2, n));
	return min(x + y, y + x);
}

int main() {
	cin >> a >> b;
	if (func(a) == func(b)) puts("YES");
	else puts("NO");
	return 0;
}