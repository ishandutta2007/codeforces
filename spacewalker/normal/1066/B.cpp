#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int n, r;
int heated[2000];
bool pHeat[2000];
int heatCount[2000];

int main() {
	int n, r; scanf("%d %d", &n, &r);
	for (int i = 0; i < n; ++i) {
		scanf("%d", heated + i);
	}
	for (int i = 0; i < n; ++i) {
		// printf("at %d\n", i);
		int pHeaterSpot = -1;
		// take the latest spot that can heat this thing
		for (int j = 0; j < n; ++j) {
			if (heated[j] == 1 && abs(j - i) < r) {
				pHeaterSpot = j;
			}
		}
		pHeat[pHeaterSpot] = true;
		// printf("picking %d\n", pHeaterSpot);
		if (pHeaterSpot == -1) {
			printf("-1\n");
			return 0;
		} else i = pHeaterSpot + r - 1;
	}
	for (int i = 0; i < n; ++i) {
		if (pHeat[i]) {
			for (int l = max(0, i - r + 1); l <= min(n-1, i + r - 1); ++l) {
				++heatCount[l];
			}
		}
	}
	int heatCt = 0;
	for (int i = 0; i < n; ++i) {
		if (heatCount[i] == 0) {
			printf("-1\n");
			return 0;
		}
		if (pHeat[i]) ++heatCt;
	}
	printf("%d\n", heatCt);
	return 0;
}