#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#pragma warning(disable : 4996)
using namespace std;
int p, x, y;
int main() {
	scanf("%d %d %d", &p, &x, &y); p -= 26;
	int ret = 999999999;
	for (int i = -30000; i <= 30000; i += 50) {
		int s = x + i;
		if (s < y) continue;
		s = (s / 50) % 475;
		for (int j = 0; j < 25; j++) {
			s = (s * 96 + 42) % 475;
			if (s == p) {
				int t = i, r = 0;
				while (t < 0 || (t + 100000) % 100 == 50) t += 50;
				r += t / 100;
				ret = min(ret, r);
			}
		}
	}
	printf("%d\n", ret);
	return 0;
}