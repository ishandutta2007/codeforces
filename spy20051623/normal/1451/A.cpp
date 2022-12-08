#include <bits/stdc++.h>
using namespace std;

int main() {
//	freopen("in.txt", "r", stdin);
	int n, i;
	cin >> n;
	while (n--) {
		cin >> i;
		if (i == 1)
			cout << 0 << endl;
		else if (i == 2)
			cout << 1 << endl;
		else if (i == 3)
			cout << 2 << endl;
		else if (i % 2 == 0)
			cout << 2 << endl;
		else
			cout << 3 << endl;
	}
	return 0;
}