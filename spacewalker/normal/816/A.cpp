#include <cstdio>
#include <algorithm>
using namespace std;

// 00:00 to 05:50
// then 10:01 to 15:51
// then 20:02 to 23:32

int minDist(int h1, int m1, int h2, int m2) {
	return max(0, (h2 - h1 - 1) * 60) + (h1 == h2 ? (m2 - m1) : (60 - m1) + m2);
}

int nextPalinP(int h, int m) {
	int oneH = h % 10;
	int tenH = h / 10;
	int revH = 10*oneH + tenH;
	//printf("time is %d:%d, next is %d:%d\n", h, m, h, revH);
	if (m <= revH) {
		return revH - m;
	} else {
		return minDist(h, m, h + 1, revH + 10);
	}
}

int main() { 
	int h, m; scanf("%d:%d", &h, &m);
	int ans = 0;
	if (h < 5 || (h == 5 && m <= 50)) {
		//printf("nextpp <5\n");
		ans = nextPalinP(h, m);
	} else if (h < 10 || (h == 10 && m <= 1)) {
		ans = minDist(h, m, 10, 1);
	} else if (h < 15 || (h == 15 && m <= 51)) {
		ans = nextPalinP(h, m);
	} else if (h < 20 || (h == 20 && m <= 2)) {
		ans = minDist(h, m, 20, 2);
	} else if (h < 23 || (h == 23 && m <= 32)) {
		ans = nextPalinP(h, m);
	} else {
		// h = 23 and the next palindrome is 00:00
		ans = (60 - m);
	}

	printf("%d\n", ans);

	return 0;
}