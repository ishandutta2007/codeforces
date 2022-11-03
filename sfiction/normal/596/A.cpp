#include <cstdio>
#include <cstdlib>

int main(){
	int n;
	int x1, y1, x2, y2, x3, y3;
	scanf("%d", &n);
	if (n == 1)
		puts("-1");
	else if (n > 2){
		scanf("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3);
		int x = abs(x1 - (x1 != x2 ? x2 : x3));
		int y = abs(y1 - (y1 != y2 ? y2 : y3));
		printf("%d\n", x * y);
	}
	else{
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		printf("%d\n", x1 == x2 || y1 == y2 ? -1 : abs(x1 - x2) * abs(y1 - y2));
	}
	return 0;
}