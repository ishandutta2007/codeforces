#include <cstdio>

int main(){
	int n, m = 15;
	scanf("%d", &n);
	for (int t; n--; ){
		scanf("%d", &t);
		if (m < t)
			break;
		m = t + 15;
	}
	if (90 < m)
		m = 90;
	printf("%d\n", m);
	return 0;
}