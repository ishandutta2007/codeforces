#include <stdio.h>
#include <algorithm>
using namespace std;
int main(){
	int n; scanf("%d", &n);
	int a = 0, b = 0, ans = 1;
	for(int i = 1; i <= n; i++){
		int x, y; scanf("%d%d", &x, &y);
		if(x >= b && y >= a) ans += min(x, y) - max(a, b) + (a != b);
		a = x; b = y;
	}
	printf("%d\n", ans);
	return 0;
}