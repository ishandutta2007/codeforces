#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios :: sync_with_stdio(false);
	string s; int a; cin >> s >> a;
	if((s == "front" && a == 1) ||
		(s == "back" && a == 2))
		cout << "L\n";
	else
		cout << "R\n";
	return 0;
}