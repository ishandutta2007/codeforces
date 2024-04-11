#include <cstdio>
using namespace std;

int t, n, x;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		x = (n - 1) / 4 + 1;
		n -= x;
		while(n--) putchar('9');
		while(x--) putchar('8');
		putchar('\n');
	}
	return 0;
}