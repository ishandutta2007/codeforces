#include <bits/stdc++.h>
using namespace std;

int main() {
//	freopen("in.txt", "r", stdin);
	long long t, x, y, i, j, k, sum;
	cin >> t;
	while (t--) {
		cin >> x >> y;
		if (y > sqrt(x + 1))
			i = sqrt(x + 1);
		else
			i = y;
		sum = (i - 1) * i / 2;
		if (y > sqrt(x + 1) && x != 1) {
			++i;
			j = 1;
			while (x / (j + 1) > i) {
				if (y + 1 >= x / j)
					sum += (x / j - x / (j + 1)) * j;
				if (y + 1 < x / j && y + 1 >= x / (j + 1))
					sum += (y + 1 - x / (j + 1)) * j;
				++j;
			}
			if (y + 1 >= x / j)
				sum += (x / j - i) * j;
			else
				sum += (y + 1 - i) * j;
		}
		cout << sum << endl;
	}
	return 0;
}