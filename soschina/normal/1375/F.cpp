#include <cstdio>
#include <iostream>
using namespace std;

int x;
long long a[4], y;

int main(){
	scanf("%lld%lld%lld", a + 1, a + 2, a + 3);
	puts("First");
	y = max(a[1], max(a[2], a[3])) - min(a[1], min(a[2], a[3]));
	printf("%lld\n", y), fflush(stdout);
	scanf("%d", &x);
	a[x] += y;
	y = 3 * a[x] - a[1] - a[2] - a[3];
	printf("%lld\n", y), fflush(stdout);
	scanf("%d", &x);
	a[x] += y;
	printf("%lld\n", (a[x] - min(a[1], min(a[2], a[3]))) / 2), fflush(stdout);
	return 0;
}