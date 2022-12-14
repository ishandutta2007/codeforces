#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int q, a, b, n, S;
	scanf("%d", &q);
	for (int i = 0; i < q; ++i) {
		scanf("%d %d %d %d", &a, &b, &n, &S);
		S -= n * min(a, S / n);
		if (S > b) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}