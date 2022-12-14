#include <cstdio>
#include <algorithm>
using namespace std;
typedef pair<int, int> ii;
int main() {
	int n;
	scanf("%d", &n);
	if (n % 2) {
		printf("NO");
		return 0;
	}
	ii xy[n];
	for (int i = 0; i < n; ++i) scanf("%d %d", &xy[i].first, &xy[i].second);
	for (int i = 0; i < n; ++i) {
		if (xy[(i + 1) % n].first - xy[i].first != xy[(n / 2 + i) % n].first - xy[(n / 2 + i + 1) % n].first || xy[(i + 1) % n].second - xy[i].second != xy[(n / 2 + i) % n].second - xy[(n / 2 + i + 1) % n].second) {
			printf("NO");
			return 0;
		}
	}
	printf("YES");
	return 0;
}