#include <cstdio>
#include <cmath>
using namespace std;

int t, n, a, b;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%d", &n, &a, &b);
		if(abs(a - b) > 1 || a + b > n - 2){
			puts("-1");
			continue;
		}
		int l = 1, r = n;
		if(a < b){
			for(int i = 1; i <= b; i++)
				printf("%d %d ", r--, l++);
			while(l <= r) printf("%d ", l++);
		}else if(a > b){
			for(int i = 1; i <= a; i++)
				printf("%d %d ", l++, r--);
			while(l <= r) printf("%d ", r--);
		}else{
			for(int i = 1; i <= a; i++)
				printf("%d %d ", l++, r--);
			while(l <= r) printf("%d ", l++);
		}
		putchar('\n');
	}
	return 0;
}