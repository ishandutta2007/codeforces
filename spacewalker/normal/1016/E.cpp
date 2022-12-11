#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
typedef long double ld;

ld xIntercept(ld ax, ld ay, ld bx, ld by) {
	if (ax == bx) return ax;
	else return (-ay * (bx - ax) / (by - ay)) + ax;
}

int main() {
	int light_y, light_l, light_r; scanf("%d %d %d", &light_y, &light_l, &light_r);
	int n; scanf("%d", &n);
	vector<ld> segLength(n), segStart(n), segEnd(n);
	vector<ld> segLengthPartSum(n + 1);
	for (int i = 0; i < n; ++i) {
		int a, b; scanf("%d %d", &a, &b);
		segLength[i] = b - a;
		segStart[i] = a;
		segEnd[i] = b;
	}
	for (int i = 1; i <= n; ++i) {
		segLengthPartSum[i] = segLengthPartSum[i-1] + segLength[i-1];
	}
	int q; scanf("%d", &q);
	for (int qta = 0; qta < q; ++qta) {
		int px, py; scanf("%d %d", &px, &py);
		ld lxit = xIntercept(light_l, light_y, px, py);
		ld rxit = xIntercept(light_r, light_y, px, py);
		// printf("intercepts %.5lf %.5lf", double(lxit), double(rxit));
		int firstFI = distance(segEnd.begin(), lower_bound(segEnd.begin(), segEnd.end(), lxit));
		int lastFI = distance(segStart.begin(), --upper_bound(segStart.begin(), segStart.end(), rxit));
		// printf("FFI LFI %d %d\n", firstFI, lastFI);
		ld shadedTimeXAxis;
		if (firstFI > lastFI || lxit >= segEnd[n-1] || rxit <= segStart[0]) shadedTimeXAxis = 0;
		else shadedTimeXAxis = (segLengthPartSum[lastFI + 1] - segLengthPartSum[firstFI]) 
			- (lxit < segStart[firstFI] ? 0 : (lxit - segStart[firstFI]))
			- (rxit > segEnd[lastFI] ? 0 : (segEnd[lastFI] - rxit));
		// printf("STIME %.7lf\n", (double)shadedTimeXAxis);
		printf("%.9lf\n", (double)(shadedTimeXAxis * ((ld)-light_y/py + 1)));
	}
	return 0;
}