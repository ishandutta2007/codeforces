#include <stdio.h>
#include <algorithm>
using namespace std;
int f[40];
int main(){
	f[0] = 1;
	for(int i = 1; i < 31; i++)
		f[i] = f[i-1] * 2;
	int n; scanf("%d", &n);
	printf("%d\n", lower_bound(f, f + 31, n + 1) - f);
	return 0;
}