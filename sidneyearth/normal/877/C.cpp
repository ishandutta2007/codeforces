#include <bits/stdc++.h>
using namespace std;
int main(){
	int n; scanf("%d", &n);
	int m = n / 2 * 3 + n % 2;
	printf("%d\n", m);
	for(int i = 2; i <= n; i += 2)
		printf("%d ", i);
	for(int i = 1; i <= n; i += 2)
		printf("%d ", i);
	for(int i = 2; i <= n; i += 2)
		printf("%d ", i);
	printf("\n");
	return 0;
}