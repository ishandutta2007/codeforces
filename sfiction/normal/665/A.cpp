#include <cstdio>

int main(){
	int a, ta, b, tb;
	int h, m;
	scanf("%d%d%d%d", &a, &ta, &b, &tb);
	scanf("%d:%d", &h, &m);
	m += (h - 5) * 60;
	int l = m - tb < 0 ? 0 : (m - tb) / b + 1;
	int r = m + ta > 1139 ? 1139 / b : (m + ta - 1) / b;
	printf("%d\n", r - l + 1);
	return 0;
}