#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	int pre = 0, cnt = 0;
	for (int t, i = 0; i < n; ++i){
		scanf("%d", &t);
		cnt -= t | pre & 1 ? -1 : pre >> 1 & 1;
		pre = pre << 1 | t;
	}
	cnt -= !(pre & 1) && (pre >> 1 & 1);
	printf("%d", cnt);
	return 0;
}