#include <cstdio>

int main(){
	int d, L, v1, v2;
	scanf("%d%d%d%d", &d, &L, &v1, &v2);
	printf("%.12f\n", (L - d) / (double)(v1 + v2));
	return 0;
}