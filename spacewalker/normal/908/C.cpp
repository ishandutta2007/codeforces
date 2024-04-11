#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	int n, r; scanf("%d %d", &n, &r);
	vector<pair<int, double>> disks(n, make_pair(0, r));
	for (int i = 0; i < n; ++i) {
		scanf("%d", &disks[i].first);
		for (int j = 0; j < i; ++j) {
			disks[i].second = max(disks[i].second, 
							  disks[j].second + sqrt(4*r*r - (disks[j].first - disks[i].first) * (disks[j].first - disks[i].first)));
		}
	}
	for (int i = 0; i < n; ++i) {
		printf("%.11f\n", disks[i].second);
	}
	return 0;
}