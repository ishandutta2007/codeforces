#include <cstdio>
#include <vector>
#include <new>
#include <cmath>
#include <algorithm>
#define INF 2000000001
using namespace std;

int main() {
	int n; scanf("%d", &n);
	vector<int> cities(n, 0);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &cities[i]);
	}
	sort(cities.begin(), cities.end());

	int bestDist = INF;
	int waysToGet = 0;
	for (int i = 1; i < n; ++i) {
		int cDist = cities[i] - cities[i-1];
		if (cDist < bestDist) {
			bestDist = cDist;
			waysToGet = 1;
		} else if (cDist == bestDist) {
			++waysToGet;
		}
	}

	printf("%d %d", bestDist, waysToGet);
	return 0;
}