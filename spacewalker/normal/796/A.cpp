#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#define INF 1000000000

using namespace std;

int main() {
	int n, girlHouse, money;

	scanf("%d %d %d", &n, &girlHouse, &money);
	--girlHouse;

	vector<int> housePrice(n, 0);

	for (int i = 0; i < n; ++i) {
		scanf("%d", &housePrice[i]);
	}

	int minDistance = INF;
	for (int house = 0; house < n; ++house) {
		if (housePrice[house] > 0 && housePrice[house] <= money) {
			minDistance = min(minDistance, (int)abs((double)house - girlHouse));
		}
	}

	printf("%d", minDistance * 10);
	return 0;
}