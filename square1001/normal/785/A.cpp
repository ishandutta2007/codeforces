#include <cstdio>
int n; char c[55];
int main() {
	scanf("%d", &n);
	int ret = 0;
	for(int i = 0; i < n; i++) {
		scanf("%s", c);
		if(c[0] == 'T') ret += 4;
		if(c[0] == 'C') ret += 6;
		if(c[0] == 'O') ret += 8;
		if(c[0] == 'D') ret += 12;
		if(c[0] == 'I') ret += 20;
	}
	printf("%d\n", ret);
	return 0;
}