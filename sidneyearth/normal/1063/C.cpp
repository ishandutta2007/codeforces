#include <stdio.h>
char s[10];
int main(){
	int n; scanf("%d", &n);
	printf("1 0\n");
	fflush(stdout);
	scanf("%s", s);
	char ty = s[0];
	int l = 0, r = 1000000000;
	for(int i = 2; i <= n; i++){
		int mid = (l + r) / 2;
		printf("%d %d\n", i, mid);
		fflush(stdout);
		scanf("%s", s);
		if(s[0] == ty) l = mid;
		else r = mid;
	}
	if(s[0] == ty){
		printf("%d %d %d %d\n", 0, l, n, r);
		fflush(stdout);
	}
	else{
		printf("%d %d %d %d\n", 0, r, n, l);
		fflush(stdout);
	}
	return 0;
}