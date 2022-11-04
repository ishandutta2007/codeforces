#include <cstdio>
using namespace std;

int t, n;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1; i <= n; i++)
			printf("()");
		putchar('\n');
		for(int i = 1; i < n; i++){
			for(int j = 1; j < i; j++)
				printf("()");
			printf("(())");
			for(int j = i + 1; j < n; j++)
				printf("()");
			putchar('\n');
		}
	}
	return 0;
}