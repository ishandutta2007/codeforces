#include <cstdio>
#define lowbit(i) (i&-i)
using namespace std;
const int N = 4e6 + 1;

int n, p, c[N];

int main(){
	scanf("%d%d", &n, &p);
	c[1]++, c[2] = p - 1;
	for(register int i = 1; i < n; i++){
		c[i] = (c[i] + c[i - 1]) % p;
		c[i + 1] = (c[i] + c[i + 1]) % p;
		for(register int j = 2, end = n / i; j <= end; j++){
			c[i * j] = (c[i * j] + c[i]) % p;
			if((i + 1) * j <= n) c[(i + 1) * j] = (c[(i + 1) * j] + p - c[i]) % p; 
		}
	}
	printf("%d", (c[n] + c[n - 1]) % p);
	return 0;
}