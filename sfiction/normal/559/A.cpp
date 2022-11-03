#include <cstdio>

int main(){
	int a[6], sum = 0;
	for (int i = 0; i < 6; ++i){
		scanf("%d", &a[i]);
		if (!(i & 1))
			sum -= a[i] * a[i];
	}
	sum += (a[0] + a[1] + a[2]) * (a[0] + a[1] + a[2]);
	printf("%d\n", sum);
	return 0;
}