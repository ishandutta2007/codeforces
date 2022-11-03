/*
 * ID: Sfiction
 * OJ: CF
 * PROB: 556A
 */
#include <cstdio>

int main(){
	int n, cnt = 0;
	scanf("%d", &n);
	getchar();
	for (int i = 0; i < n; ++i){
		char c = getchar();
		cnt += c == '1';
	}
	printf("%d\n", cnt * 2 <= n ? n - cnt * 2 : cnt * 2 - n);

	return 0;
}