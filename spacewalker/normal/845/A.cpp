#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int n; scanf("%d", &n);
	vector<int> rat(2*n, 0);
	for (int i = 0; i < 2*n; ++i) {
		scanf("%d", &rat[i]);
	}
	sort(rat.begin(), rat.end());
	printf("%s", (rat[n-1] != rat[n] ? "YES" : "NO"));
	return 0;
}