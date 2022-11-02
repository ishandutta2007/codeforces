#include <bits/stdc++.h>
using namespace std;
int a[10];
int main()
{
	int n, mul, k;
	scanf("%d", &n);
	for( int i = 1; i <= n - 1; i ++){
		for( int j = 1; j <= n -1; j ++)
	{
		mul = i * j;
		k = 0;
		while(mul){
			a[k] = mul % n;
			mul /= n;
			k ++;
		}
		for( int l = k - 1; l >= 0; l --)
			printf("%d",a[l]);
		printf(" ");
	}
	printf("\n");
	}
	return 0;
}