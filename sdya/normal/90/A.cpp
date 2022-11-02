#include <iostream>
using namespace std;

int main() {
	int score = 0;
	int r, g, b;
	cin >> r >> g >> b;
	int t = 0;
	while (r > 0 || g > 0 || b > 0) {
		if (r > 0 && t % 3 == 0) {
			score = max(score, t + 30);
			r -= 2;
		}
		if (g > 0 && t % 3 == 1) {
			score = max(score, t + 30);
			g -= 2;
		}
		if (b > 0 && t % 3 == 2) {
			score = max(score, t + 30);
			b -= 2;
		}
		++t;
	}
	cout << score << endl;
	return 0;
}