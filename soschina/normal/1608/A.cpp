#include <cstdio>
using namespace std;

int t, n;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1; i <= n; i++)
			printf("%d ", i + 1);
		putchar('\n');
	}
	return 0;
}