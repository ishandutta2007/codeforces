#include <cstdio>
using namespace std;

int t, n;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		n--;
		int m = 1;
		while(m <= n) m <<= 1;
		m >>= 1;
		for(int i = m - 1; i >= 0; i--)
			printf("%d ", i);
		for(int i = m; i <= n; i++)
			printf("%d ", i);
		putchar('\n');
	}
	return 0;
}