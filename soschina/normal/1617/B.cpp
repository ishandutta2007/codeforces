#include <cstdio>
using namespace std;

int t, n;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		n--;
		if(n & 1) printf("%d 2 1", n - 2);
		else if((n >> 1) & 1) printf("%d %d 1", n / 2 - 2, n / 2 + 2);
		else printf("%d %d 1", n / 2 - 1, n / 2 + 1);
		putchar('\n');
	}
	return 0;
}