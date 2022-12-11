#include <cstdio>
#include <vector>

using namespace std;
typedef long long ll;

int main() {
	int n, m; scanf("%d %d", &n, &m);
	vector<int> firstb(n, 0);
	vector<int> secondb(m, 0);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &firstb[i]);
	}
	for (int i = 0; i < m; ++i) {
		scanf("%d", &secondb[i]);
	}
	int frontier1 = 0;
	int frontier2 = 0;
	ll cPart1Sum = 0;
	ll cPart2Sum = 0;
	int partitions = 1;
	while (frontier1 < n && frontier2 < m) {
		//printf("f1 f2 = %d %d\n", frontier1, frontier2);
		if (cPart2Sum == 0 && cPart1Sum == 0) {
			cPart1Sum = firstb[frontier1++];
			continue;
		} else if (cPart1Sum == cPart2Sum) {
			// this is a new partition!
			//printf("splitting at %d %d\n", frontier1, frontier2);
			cPart1Sum = 0;
			cPart2Sum = 0;
			++partitions;
			continue;
		} else if (cPart1Sum < cPart2Sum) {
			cPart1Sum += firstb[frontier1++];
		} else {
			cPart2Sum += secondb[frontier2++];
		}
	}
	printf("%d\n", partitions);
	return 0;
}