#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int t;
	long long x;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		scanf("%lld", &x);
		if (x >= 15 && x % 14 > 0 && x % 14 < 7) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}