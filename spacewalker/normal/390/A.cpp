#include <cstdio>
#include <set>
using namespace std;
int main() {
	int n; scanf("%d", &n);

	set<int> xClockPos, yClockPos;
	int xi, yi;

	while (n--) {
		scanf("%d %d", &xi, &yi);
		xClockPos.insert(xi);
		yClockPos.insert(yi);
	}

	printf("%lu\n", min(xClockPos.size(), yClockPos.size()));
	return 0;
}