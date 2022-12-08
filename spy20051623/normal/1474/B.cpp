#include <bits/stdc++.h>
using namespace std;

int is(int x) {
	for (int i = 2; i <= sqrt(x); ++i) {
		if (x % i == 0)
			return 0;
	}
	return 1;
}

main() {
	int t, d, i, j;
	cin >> t;
	while (t--) {
		cin >> d;
		i = 1 + d;
		while (is(i) == 0)
			++i;
		j = i + d;
		while (is(j) == 0)
			++j;
		cout << i *j << endl;
	}
}