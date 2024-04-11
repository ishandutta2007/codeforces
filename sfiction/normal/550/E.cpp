/*
 * ID: Sfiction
 * OJ: CF
 * PROB: 55E
 */
#include <cstdio>

const int MAXN = 1E5 + 10;

int n;
int a[MAXN];

int main(){
	int firstZero = -1;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i){
		scanf("%d", &a[i]);
		if (!~firstZero && !a[i])
			firstZero = i;
	}

	if (a[n - 1] == 1)
		puts("NO");
	else if (n == 1)
		puts("YES\n0");
	else if (firstZero == n - 2)
		puts("NO");
	else if (firstZero == n - 1){
		puts("YES");
		for (int i=0;i<n-1;++i)
			printf("1->");
		puts("0");
	}
	else{
		puts("YES");
		for (int i=0;i<firstZero;++i)
			printf("1->");
		printf("0->(%d", a[firstZero + 1]);
		for (int i=firstZero+2;i<n-1;++i)
			printf("->%d", a[i]);
		puts(")->0");
	}

	return 0;
}