#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <set>

using namespace std;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int a, x, y;
	cin >> a >> x >> y;
	a += a, x += x, y += y;
	if (y < 0 || y % a == 0) {
		printf("-1\n");
		return 0;
	}

	int level = y / a;
	if (level == 0) {
		if (x > -a / 2 && x < a / 2) {
			printf("1\n");
			return 0;
		} else {
			printf("-1\n");
			return 0;
		}
	}

	if (level == 1) {
		if (x > -a / 2 && x < a / 2) {
			printf("2\n");
			return 0;
		} else {
			printf("-1\n");
			return 0;
		}
	}

	int cur = 2 * a;
	int index = 2;
	for (;;) {
		if (y > cur && y < cur + a) {
			if (x > -a && x < 0) {
				printf("%d\n", index + 1);
			} else if (x > 0 && x < a) {
				printf("%d\n", index + 2);
			} else {
				printf("-1\n");
			}
			return 0;
		}
		if (y > cur + a && y < cur + a + a) {
			if (x > -a / 2 && x < a / 2) {
				printf("%d\n", index + 3);
			} else {
				printf("-1\n");
			}
			return 0;
		}
		cur += 2 * a;
		index += 3;
	}


	return 0;
}