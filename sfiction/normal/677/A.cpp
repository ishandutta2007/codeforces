#include <cstdio>

int main(){
	int n, h;
	scanf("%d%d", &n, &h);
	int ans = n;
	for (int t, i = 0; i < n; ++i){
		scanf("%d", &t);
		ans += t > h;
	}
	printf("%d\n", ans);
	return 0;
}