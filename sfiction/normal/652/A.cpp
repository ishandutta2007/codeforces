#include <cstdio>

int main(){
	int h1, h2, a, b;
	scanf("%d%d", &h1, &h2);
	scanf("%d%d", &a, &b);
	if (a <= b){
		puts(h1 + 8 * a < h2 ? "-1" : "0");
		return 0;
	}
	int t = 14, day = 0;
	for (; h1 < h2; t = (t + 1) % 24, day += t == 0)
		if (10 <= t && t < 22)
			h1 += a;
		else
			h1 -= b;
	printf("%d\n", day);
	return 0;
}