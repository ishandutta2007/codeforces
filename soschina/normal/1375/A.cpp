#include <cstdio>
using namespace std;

int t, n, a;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		while(n--){
			scanf("%d", &a);
			printf("%d ", (a > 0) ^ (n & 1) ? a : -a);
		}
		putchar('\n');
	}
	return 0;
}