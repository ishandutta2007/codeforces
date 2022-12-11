#include <cstdio>

int main() {
	int l, r, a; scanf("%d %d %d", &l, &r, &a);
	for (int ct = 500; ct >= 0; --ct) {
		// we need ct left handers and ct right handers
		int ambiToLeft = (l >= ct ? 0 : ct - l);
		int ambiToRight = (r >= ct ? 0 : ct - r);
		if (ambiToLeft + ambiToRight <= a) {
			printf("%d\n", 2*ct);
			break;
		}
	}
	return 0;
}