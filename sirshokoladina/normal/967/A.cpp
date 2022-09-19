#include <iostream>

using namespace std;

int main () {
	int s, n;
	cin >> n >> s;
	int a[n][2];
	for (int i = 0; i < n; ++i) {
		cin >> a[i][0] >> a[i][1];
	}
	
	int b[n];
	for (int i = 0; i < n; ++i) {
		b[i] = a[i][0] * 60 + a[i][1];
	}
	
	if (b[0] >= s + 1) {
		printf("0 0\n");
		return 0;
	}
	for (int i = 0; i < n; ++i) {
		if (b[i + 1] - b[i] >= 2 * s + 2) {
			int t = b[i] + s + 1;
			int fs = t / 60;
			int sc = t % 60;
			printf("%d %d\n", fs, sc);
			return 0;
		}
	}
	
	return 0;
}