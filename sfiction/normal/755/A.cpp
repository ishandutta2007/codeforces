#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	for (int i = 1; true; ++i){
		int t = i * n + 1;
		for (int j = 2; j * j <= t; ++j)
			if (t % j == 0){
				printf("%d\n", i);
				return 0;
			}
	}
	return 0;
}