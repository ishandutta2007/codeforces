#include <cstdio>

char s[200];

int main(){
	int n, p, q;
	scanf("%d%d%d", &n, &p, &q);
	scanf("%s", s);
	bool flag = false;
	for (int i = 0; p * i <= n; ++i)
		if ((n - p * i) % q == 0){
			printf("%d\n", i + (n - p * i) / q);
			for (int j = 0; j < i; ++j){
				for (int k = 0; k < p; ++k)
					putchar(s[j * p + k]);
				puts("");
			}
			for (int j = 0; j < (n - p * i) / q; ++j){
				for (int k = 0; k < q; ++k)
					putchar(s[i * p + j * q + k]);
				puts("");
			}
			flag = true;
			break;
		}
	if (!flag)
		puts("-1");
	return 0;
}