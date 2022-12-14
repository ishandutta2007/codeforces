#include <cstdio>
#include <algorithm>
#include <cstdlib>
using namespace std;
int main() {
	int n, a;
	long long ans = 0, bal = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a);
		ans += a;
		if (a % 2) {
			if (i % 2) ++bal;
			else --bal;
		}
	}
	printf("%lld", (ans - abs(bal)) / 2);
	return 0;
}