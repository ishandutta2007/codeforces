#include <cstdio>

int main(){
	int a, b, c;
	int x, y, z;
	scanf("%d%d%d", &a, &b, &c);
	scanf("%d%d%d", &x, &y, &z);
	int cnt = 0;
	cnt += a > x ? a - x >> 1 : a - x;
	cnt += b > y ? b - y >> 1 : b - y;
	cnt += c > z ? c - z >> 1 : c - z;
	puts(cnt >= 0 ? "Yes" : "No");
	return 0;
}