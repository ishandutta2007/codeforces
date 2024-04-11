#include <cstdio>
int n; char c[1000009];
int main() {
	int ret = 0, mul = 0;
	while (c[n] = getchar(), c[n] != '\n') {
		if (c[n] == 'a') {
			mul = mul * 2 + 1;
			if (mul >= 1000000007) mul -= 1000000007;
		}
		else {
			ret += mul;
			if (ret >= 1000000007) ret -= 1000000007;
		}
		n++;
	}
	printf("%d\n", ret);
	return 0;
}