#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int t, candies[3];
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		for (int j = 0; j < 3; ++j) scanf("%d", &candies[j]);
		sort(candies, candies + 3);
		if (candies[2] <= candies[1] + candies[0]) printf("%d\n", (candies[0] + candies[1] + candies[2]) / 2);
		else printf("%d\n", candies[0] + candies[1]);
	}
	return 0;
}