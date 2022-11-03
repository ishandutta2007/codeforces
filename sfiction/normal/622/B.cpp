#include <cstdio>

int main(){
	int h, m, t;
	scanf("%d:%d%d", &h, &m, &t);
	h = (h + (m += t) / 60) % 24;
	m %= 60;
	printf("%02d:%02d\n", h, m);
	return 0;
}