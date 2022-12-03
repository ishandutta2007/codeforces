#include <algorithm>
#include <cstdio>
#include <cstring>
#include <climits>
#include <cmath>
#include <queue>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

double length(int x[], int y[]) {
	double res = 0;
	for (int i = 0; i < 3; i++) {
		int dx = x[i + 1] - x[i], dy = y[i + 1] - y[i];
		res += sqrt((double)(dx * dx + dy * dy));
	}
	return res;
}

int main() {
	int n, m; scanf("%d%d", &n, &m);
	bool swapped = false;
	if (n < m) {
		swapped = true;
		swap(n, m);
	}
	int x[4], y[4];
	if (m == 0) {
		x[0] = 1; y[0] = 0;
		x[1] = n; y[1] = 0;
		x[2] = 0; y[2] = 0;
		x[3] = n - 1; y[3] = 0;
	}
	else {
		int x1[4], y1[4];
		x1[0] = 0; y1[0] = 0;
		x1[1] = n; y1[1] = m;
		x1[2] = 0; y1[2] = m;
		x1[3] = n; y1[3] = 0;
		int x2[4], y2[4];
		x2[0] = n; y2[0] = m - 1;
		x2[1] = 0; y2[1] = 0;
		x2[2] = n; y2[2] = m;
		x2[3] = 0; y2[3] = 1;
		if (length(x1, y1) > length(x2, y2)) {
			x[0] = x1[0]; y[0] = y1[0];
			x[1] = x1[1]; y[1] = y1[1];
			x[2] = x1[2]; y[2] = y1[2];
			x[3] = x1[3]; y[3] = y1[3];
		}
		else {
			x[0] = x2[0]; y[0] = y2[0];
			x[1] = x2[1]; y[1] = y2[1];
			x[2] = x2[2]; y[2] = y2[2];
			x[3] = x2[3]; y[3] = y2[3];
		}
	}
	if (swapped)
		for (int i = 0; i < 4; i++)
			swap(x[i], y[i]);
	for (int i = 0; i < 4; i++)
		printf("%d %d\n", x[i], y[i]);
}