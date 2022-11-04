#include <cstdio>
using namespace std;

int t, n, k;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &k);
		if(k == n - 1){
			if(n == 4){
				puts("-1");
				continue;
			}
			printf("%d %d\n", n - 2, n - 1);
			printf("%d %d\n", 1, 0);
			printf("%d %d\n", 3, (n - 1) ^ 2);
			printf("%d %d\n", 2, (n - 1) ^ 3);
			for(int i = 4; i < n / 2; i++)
				printf("%d %d\n", i, (n - 1) ^ i);
			continue;
		}
		if(k == 0){
			for(int i = 0; i < n / 2; i++)
				printf("%d %d\n", i, (n - 1) ^ i);
			continue;
		}
		printf("%d %d\n", 0, (n - 1) ^ k);
		printf("%d %d\n", k, n - 1);
		for(int i = 1; i < n / 2; i++) if(i != k && i != ((n - 1) ^ k))
			printf("%d %d\n", i, (n - 1) ^ i);
	}
	return 0;
}