/*
 * ID: Sfiction
 * OJ: CF
 * PROB: 556B
 */
#include <cstdio>

bool work(){
	int n, a0, a;
	scanf("%d%d", &n, &a0);
	for (int i = 1; i < n; ++i){
		scanf("%d", &a);
		if ((a + n + (i & 1 ? a0 : -a0)) % n != i)
			return false;
	}
	return true;
}

int main(){
	puts(work() ? "Yes" : "No");

	return 0;
}