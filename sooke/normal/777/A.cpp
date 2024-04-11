#include <iostream>
#include <cstdio>

std::string s = "012102120210201021";
int n, x;

int main() {
	scanf("%d%d", &n, &x);
	printf("%d\n", s[n % 6 * 3 + x] ^ '0');
	return 0;
}