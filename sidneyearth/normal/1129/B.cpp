#include <stdio.h>
#include <algorithm>
using namespace std;
int main(){
	int k; scanf("%d", &k);
	int n = 2000, s = k + n;
	printf("%d\n", n);
	printf("-1 ");
	for(int i = 2; i <= n; i++){
		int a = min(s, 1000000);
		s -= a;
		printf("%d%c", a, " \n"[i==n]);
	}
	return 0;
}