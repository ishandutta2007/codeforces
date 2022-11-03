#include <cstdio>
#include <cmath>

int main(){
	int d, h, v, e;
	scanf("%d%d%d%d", &d, &h, &v, &e);
	double f = v / (acos(-1) * d * d / 4);
	if (f < e)
		puts("NO");
	else
		printf("YES\n%.12f\n", h / (f - e));
	return 0;
}