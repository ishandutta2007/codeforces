#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int n, cl = 0;
	bool hasmismatch = false;
	char c;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf(" %c", &c);
		if (c == '(') cl += 1;
		else if (cl > 0) cl -= 1;
		else if (hasmismatch) {
			printf("No");
			return 0;
		} else hasmismatch = true;
	}
	if (cl == 1 && hasmismatch) printf("Yes");
	else if (cl == 0 && !hasmismatch) printf("Yes");
	else printf("No");
	return 0;
}