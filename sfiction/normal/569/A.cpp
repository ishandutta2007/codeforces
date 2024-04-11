/*
 * ID: Sfiction
 * OJ: CF
 * PROB: 569A
 */
#include <cstdio>

int main(){
	int T, S, q;
	int ans;

	scanf("%d%d%d", &T, &S, &q);
	for (ans = 0; T > S; ++ans)
		T = T / q + !!(T % q);
	printf("%d\n", ans);

	return 0;
}