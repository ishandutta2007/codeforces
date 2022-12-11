#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;

int main() {
	int n, k; scanf("%d %d", &n, &k);
	map<int, int> rem;
	for (int i = 0; i < n; ++i) {
		int x; scanf("%d", &x);
		++rem[x];
	}
	int maxUses = 0;
	for (auto dish_c : rem) maxUses = max(maxUses, dish_c.second);
	int dishesServed = maxUses + (maxUses % k == 0 ? 0 : k - (maxUses % k));
	printf("%d\n", dishesServed * (int)rem.size() - n);
	return 0;
}