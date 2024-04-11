/*
 * ID: Sfiction
 * OJ: CF
 * PROB: 549C
 */
#include <cstdio>

int main(){
	int n, k;
	int odd = 0, even;

	scanf("%d%d", &n, &k);
	for (int i=0;i<n;++i){
		int t;
		scanf("%d", &t);
		odd += t & 1;
	}
	even = n - odd;

	const char *S = "Stannis", *D = "Daenerys";
	if (n == k)
		puts(odd & 1 ? S : D);
	else if ((n - k) & 1){
		if (k & 1)
			puts((n - k) / 2 >= odd ? D : S);
		else
			puts((n - k) / 2 >= odd || (n - k) / 2 >= even ? D : S);
	}
	else{
		if (k & 1)
			puts((n - k) / 2 >= even ? S : D);
		else
			puts(D);
	}

	return 0;
}