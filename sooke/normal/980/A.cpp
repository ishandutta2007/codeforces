#include <cstdio>

char c = getchar();
int x, y;

int main() {
	while (c == '-' || c == 'o') {
		if (c == '-') {
			x++;	
		} else {
			y++;
		}
		c = getchar();
	}
	if (y == 0 || x % y == 0) {
		printf("YES\n");
	} else {
		printf("NO\n");
	}
	return 0;
}

// By Sooke.
// CF980A Links and Pearls.