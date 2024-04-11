#include <cstdio>

int main(){
	int m;
	scanf("%d", &m);
	for (int i = 5; m > 0; i += 5){
		for (int t = i; t % 5 == 0; t /= 5)
			--m;
		if (m == 0){
			puts("5");
			for (int j = 0; j < 5; ++j)
				printf("%d%c", i + j, "\n "[j < 4]);
			break;
		}
	}
	if (m)
		puts("0");
	return 0;
}