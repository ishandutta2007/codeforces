#include <cstdio>
#include <algorithm>
using namespace std;

int dist(int dsum, char digs[3]) {
	sort(digs, digs + 3);
	int cds = digs[0] + digs[1] + digs[2];
	if (dsum == cds) {
		return 0;
	} else if (dsum < cds) {
		// we need to lower
		if (digs[0] + digs[1] <= dsum) {
			return 1;
		} else if (digs[0] <= dsum) {
			return 2;
		} else {
			return 3;
		}
	} else {
		// we need to increase
		if (9 + digs[1] + digs[2] >= dsum) {
			return 1;
		} else if (18 + digs[2] >= dsum) {
			return 2;
		} else {
			return 3;
		}
	}
}

int main() {
	char h1[3] = {0};
	char h2[3] = {0};
	for (int i = 0; i < 3; ++i) {
		scanf("%c", &h1[i]); h1[i] -= '0';
	}
	for (int i = 0; i < 3; ++i) {
		scanf("%c", &h2[i]); h2[i] -= '0';
	}
	sort(h1, h1 + 3);
	sort(h2, h2 + 3);
	int minRes = 6;
	for (int i = 0; i <= 27; ++i) {
		minRes = min(minRes, dist(i, h1) + dist(i, h2));
	}
	printf("%d\n", minRes);
	return 0;
}