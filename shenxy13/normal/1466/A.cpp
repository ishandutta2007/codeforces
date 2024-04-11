#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
int main() {
	int t;
	scanf("%d", &t);
	for (int h = 0; h < t; ++h) {
		int n;
		scanf("%d", &n);
		int x[n];
		for (int i = 0; i < n; ++i) scanf("%d", &x[i]);
		set<int> area;
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) area.insert(x[j] - x[i]);
		}
		printf("%lu\n", area.size());
	}
	return 0;
}