#include <cstdio>
#include <algorithm>

int pedals[50] = {0};
int wheel[50] = {0};

int main() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &pedals[i]);
	}
	int m; scanf("%d", &m);
	for (int j = 0; j < m; ++j) {
		scanf("%d", &wheel[j]);
	}

	int bestRatio = -1;
	int waysToGet = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (wheel[j] % pedals[i] != 0) {
				continue;
			}
			int cRatio = wheel[j] / pedals[i];
			if (cRatio > bestRatio) {
				waysToGet = 1;
				bestRatio = cRatio;
			} else if (cRatio == bestRatio) {
				++waysToGet;
			}
		}
	}

	printf("%d", waysToGet); 

}