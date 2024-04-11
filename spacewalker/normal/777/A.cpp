#include <cstdio>
#include <vector>
#include <string>
#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;

int main() {

	int n; scanf("%d", &n);
	int x; scanf("%d", &x);
	int ans = -1;

	switch (n%6) {
		case 0:
			ans = x;
			break;
		case 1:
			if (x == 2) {
				ans = 2;
			} else {
				ans = 1 - x;
			}
			break;
		case 2:
			ans = (x+1)%3;
			break;
		case 3:
			ans = (2-x);
			break;
		case 4:
			ans = (x+2) % 3;
			break;
		case 5:
			if (x == 0) {
				ans = 0;
			} else {
				ans = 3-x;
			}
			break;
		default:
			break;
	}

	printf("%d", ans);

	return 0;
}