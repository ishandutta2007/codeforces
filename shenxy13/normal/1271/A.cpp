#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int a, b, c, d, e, f;
	scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);
	b = min(b, c);
	if (d >= a + b) printf("%d", a * e + b * f);
	else if (e > f) printf("%d", min(a, d) * e + max(0, (d - a)) * f);
	else printf("%d", min(b, d) * f + max(0, (d - b)) * e);
	return 0;
}