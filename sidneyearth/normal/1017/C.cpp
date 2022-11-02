#include <stdio.h>
int main(){
	int n; scanf("%d", &n);
	int k = 0;
	while((k + 1) * (k + 1) <= n) k++;
	for(int i = 1; i <= n / k; i++)
		for(int j = i * k; j > (i - 1) * k; j--)
			printf("%d ", j);
	for(int i = n; i > n / k * k; i--)
		printf("%d ", i);
	printf("\n");
	return 0;
}