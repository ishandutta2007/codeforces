#include <stdio.h>
#include <algorithm>
using namespace std;
int main(){
	int a, b, c; 
	scanf("%d%d%d", &a, &b, &c);
	printf("%lld\n", 2ll * c + 2ll * min(a, b) + (a != b));
	return 0;
}