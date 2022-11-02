#include<stdio.h>
int n, k, t, d;
int main(){
	scanf("%d %d %d %d", &n, &t, &k, &d);
	int tmp = (d + t) / t * k;
	if(n > tmp) puts("YES");
	else puts("NO");
}