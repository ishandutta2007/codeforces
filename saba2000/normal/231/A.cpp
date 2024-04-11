#include <stdio.h>
 
int main() {
 
	int p, t, v, n, counter = 0;
	scanf("%d", &n);
	while (n--) {
		scanf("%d%d%d", &p, &t, &v);
		if (p + t + v >= 2) {
			counter++;
		}
	}
 
	printf("%d", counter);
	return 0;
}