#include <bits/stdc++.h>
using namespace std;

int n;
char s[30];

int main() {
	scanf("%d\n", &n);
	int ans = 0;
	while (n --) {
		scanf("%s", s);
		if (strcmp(s, "Tetrahedron") == 0) ans += 4;
		else if (strcmp(s, "Cube") == 0) ans += 6;
		else if (strcmp(s, "Octahedron") == 0) ans += 8;
		else if (strcmp(s, "Dodecahedron") == 0) ans += 12;
		else if (strcmp(s, "Icosahedron") == 0) ans += 20;
	}
	printf("%d\n", ans);
	return 0;
}