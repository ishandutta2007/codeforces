#include <cstdio>
#include <vector>
#include <string>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

vector<int> now;
vector<int> later;

bool forSorting(int indexA, int indexB) {
	int Adiff = now[indexA] - later[indexA];
	int Bdiff = now[indexB] - later[indexB];
	if (Adiff == Bdiff) {
		return now[indexA] < now[indexB];
	} else {
		return Adiff < Bdiff;
	}
}

int main() {
	int n, k; scanf("%d %d", &n, &k);

	now = vector<int>(n, 0);
	later = vector<int>(n, 0);

	for (int i = 0; i < n; ++i) {
		scanf("%d", &now[i]);
	}

	for (int i = 0; i < n; ++i) {
		scanf("%d", &later[i]);
	}

	vector<int> sortedIs(n, 0);
	for (int i = 0; i < n; ++i) {
		sortedIs[i] = i;
	}

	sort(sortedIs.begin(), sortedIs.end(), forSorting);

	long price = 0; 
	for (int i = 0; i < n; ++i) {
		int ci = sortedIs[i];
		if (i < k || now[ci] - later[ci] < 0) {
			//printf("add now price of %dth item \n", ci);
			price += now[ci];
		} else {
			//printf("add later price of %dth item \n", ci);
			price += later[ci];
		}
	}

	printf("%ld", price);

	return 0;
}