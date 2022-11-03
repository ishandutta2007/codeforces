/*
 * ID: Sfiction
 * OJ: CF
 * PROB: 550D
 */
#include <cstdio>

int main(){
	int k;
	scanf("%d", &k);
	if (k == 1){
		puts("YES\n2 1\n1 2");
	}
	else if (k & 1){
		puts("YES");
		printf("%d %d\n", 2 * k + 4, k * (k + 2));
		printf("%d %d\n", k + 2, 2 * k + 4);
		for (int l=0;l<2;++l){
			int d = l ? k + 3 : 1;
			printf("%d %d\n", k - 1 + d, k + d);
			for (int i=0;i<k-1;++i){
				printf("%d %d\n", k - 1 + d, i + d);
				printf("%d %d\n", k + d, i + d);
				printf("%d %d\n", k + 1 + d, i + d);
			}
			for (int i=0;i<k-1;++i)
				for (int j=i+1;j<k-1;++j)
					if (i & 1 || (j - i) != 1)
						printf("%d %d\n", i + d, j + d);
		}
	}
	else
		puts("NO");
	return 0;
}