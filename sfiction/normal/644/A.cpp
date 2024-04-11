#include <cstdio>

int main(){
	int n, a, b;
	scanf("%d%d%d", &n, &a, &b);
	if (a * b < n)
		puts("-1");
	else{
		for (int t, i = 0; i < a; ++i)
			for (int j = 0; j < b; ++j)
				printf("%d%c", (t = (i * b + j ^ !(b & 1) & i) + 1) <= n ? t : 0, "\n "[j < b - 1]);
	}
	return 0;
}