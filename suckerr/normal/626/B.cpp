#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

const int N = 210 + 2;

bool state[N][N][N];
int n;

void go(int r, int g, int b) {
	if (state[r][g][b]) {
		return ;
	}
	state[r][g][b] = 1;
	if (r && g) {
		go(r - 1, g - 1, b + 1);
	}
	if (g && b) {
		go(r + 1, g - 1, b - 1);
	}
	if (r && b) {
		go(r - 1, g + 1, b - 1);
	}
	if (r > 1) {
		go(r - 1, g, b);
	}
	if (g > 1) {
		go(r, g - 1, b);
	}
	if (b > 1) {
		go(r, g, b - 1);
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			for (int k = 0; k <= n; k++) {
				state[i][j][k] = 0;
			}
		}
	}
	static char s[N];
	scanf("%s", s);
	int r = 0, g = 0, b = 0;
	for (int i = 0; i < n; i++) {
		r += (s[i] == 'R');
		g += (s[i] == 'G');
		b += (s[i] == 'B');
	}
	go(r, g, b);
	if (state[0][0][1]) {
		printf("B");
	}
	if (state[0][1][0]) {
		printf("G");
	}
	if (state[1][0][0]) {
		printf("R");
	}
	cout << endl;
	return 0;
}