#include <bits/stdc++.h>

using namespace std;

int main() {
	int a;
	cin >> a;
	if (a == 1)
		cout << "1 1\n1\n";
	else {
		cout << 2 * a - 2 << ' ' << 2 << '\n';
		cout << 1 << ' ' << 2 << '\n';
	}
}