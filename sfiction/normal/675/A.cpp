#include <cstdio>

int main(){
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	puts(!c && a == b || c && (b - a) % c == 0 && (b - a) / c >= 0 ? "YES" : "NO");
	return 0;
}