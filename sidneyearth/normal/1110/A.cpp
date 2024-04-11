#include <stdio.h>
int main(){
	int b, n; scanf("%d%d", &b, &n);
	int t = 0, x;
	for(int i = 1; i <= n; i++){
		scanf("%d", &x);
		t ^= (x & 1);
	}
	if(b & 1) printf("%s\n", t & 1 ? "odd" : "even");
	else printf("%s\n", x & 1 ? "odd" : "even");
	return 0;
}