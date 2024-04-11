#include <cstdio>

using namespace std;

int rd() {
	int x = 0; char c= getchar();
	while (c > '9' || c < '0') c = getchar();
	while (c >= '0' && c <= '9') x = x * 10 + c - 48, c = getchar();
	return x;
}

char op[10];
int n, m, ans, i, j = 1, s[400005];

int main() {
	for(n = rd(), m = n << 1; m; m --) {
		scanf("%s", op);
		if (op[0] == 'a') s[++i] = rd();
		else  {
			if (i && s[i] != j) ans ++, i = 0;
			else if (i) i --;
			if (++j == n) break;
		}
	}
	printf("%d\n", ans);
	return 0;
}