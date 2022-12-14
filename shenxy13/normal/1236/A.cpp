#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int t, a, b, c;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		int ans = 0;
		scanf("%d %d %d", &a, &b, &c);
		ans += min(b, c / 2);
		b -= ans;
		ans += min(a, b / 2);
		printf("%d\n", 3 * ans);
	}
	return 0;
}