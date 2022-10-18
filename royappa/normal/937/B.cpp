#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

int main()
{
	LL p, y;
	cin >> p >> y;

	for (LL q = y; q > p; q--) {
		LL d = 2;
		bool kindaPrime = true;
		while (d*d <= q && d <= p) {
			if (q%d == 0) {
				kindaPrime = false;
				break;
			}
			d++;
		}
		if (kindaPrime) {
			cout << q << endl;
			exit(0);
		}

	}
	cout << -1 << endl;

	exit(0);
}