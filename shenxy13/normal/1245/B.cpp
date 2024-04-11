#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		int n, a, b, c, ans = 0;
		scanf("%d %d %d %d", &n, &a, &b, &c);
		char rolls[n], nextchar;
		for (int j = 0; j < n; ++j) {
			scanf(" %c", &nextchar);
			if (nextchar == 'R') {
				if (b != 0) rolls[j] = 'P', --b, ++ans;
				else rolls[j] = 'X';
			} else if (nextchar == 'P') {
				if (c != 0) rolls[j] = 'S', --c, ++ans;
				else rolls[j] = 'X';
			} else {
				if (a != 0) rolls[j] = 'R', --a, ++ans;
				else rolls[j] = 'X';
			}
		}
		if (ans * 2 >= n) {
			printf("YES\n");
			for (int j = 0; j < n; ++j) {
				if (rolls[j] == 'X') {
					if (a != 0) printf("R"), --a;
					else if (b != 0) printf("P"), --b;
					else printf("S"), --c;
				} else printf("%c", rolls[j]);
			}
		} else printf("NO");
		printf("\n");
	}
	return 0;
}