#include <bits/stdc++.h>

using namespace std;

char cfloor[200];

int main() {
	int n, m; scanf("%d %d", &n, &m);
	vector<int> fHouse(n, m + 1), lHouse(n, 0);
	for (int i = n - 1; i >= 0; --i) {
		scanf("%s", cfloor);
		for (int j = 0; j < m + 2; ++j) if (cfloor[j] == '1') lHouse[i] = j; 
		for (int j = m + 1; j >= 0; --j) if (cfloor[j] == '1') fHouse[i] = j; 
	}
	while (n > 0 && lHouse[n-1] == 0) --n;
	if (n == 0) {
		printf("0\n");
		return 0;
	}
	int ans = 1000000000;
	for (int k = 0; k < (1 << (n - 1)); ++k) {
		// printf("att bitmask %d\n", k);
		int cost = n - 1; // inter-stairs cost
		bool onLeft = true;
		for (int floor = 0; floor < n - 1; ++floor) {
			// printf("to %d floor: cost %d\n", floor, cost);
			// printf("FH LH %d %d\n", fHouse[floor], lHouse[floor]);
			bool goToLeft = (k & (1 << floor)) > 0;
			// printf("%sgoing left\n", (goToLeft ? "" : "not "));
			if (goToLeft && onLeft) {
				cost += 2*lHouse[floor];
			} else if (!goToLeft && !onLeft) {
				cost += 2*(m+1-fHouse[floor]);
			} else {
				cost += m + 1;
			}
			onLeft = goToLeft;
		}
		// printf("end cost %d\n", cost);
		if (onLeft) cost += lHouse[n-1];
		else cost += (m+1)-(fHouse[n-1]);
		ans = min(ans, cost);
	}
	printf("%d\n", ans);
	return 0;
}